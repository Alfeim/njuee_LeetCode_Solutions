/********************************************
作者:Alfeim
题目:搜索旋转排序数组
时间消耗:64ms
解题思路:1.滑动窗口 2.累计和
********************************************/

//滑动窗口法
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        
        //统计每个数字的出现次数
        map<int,int> counts;
        //用来表示每个数字对应的起始位置
        unordered_map<int,int> pos;
        
        //offset表示之前的数字总数
        int offset = 0;
        
        //先统计每个数的出现次数并存放于map中(自动按照元素大小排序)
        for( auto i : arr ) counts[i]++;
        
        //然后遍历map来得到每个元素的起始位置
        for(auto i : counts){ 
            pos[i.first] = offset ; 
            offset += counts[i.first];
        }
      
        
        
        int res = 0,
            left = 0,
            right = -1, 
            n = arr.size();
            
        //tmpcount用于计算在滑动窗口内某个元素的出现次数
        unordered_map<int,int> tmpcount;
        while(left < n && right < n){
            res++;
            
            int border = max(pos[arr[left]],left);
            
            while(right < n && right < border){
                right++;
                int cur = arr[right];
                border = max(border,pos[cur] + tmpcount[cur]);
                tmpcount[cur]++;
            }
            
            tmpcount.clear();
            left = right + 1;     
        }
        
        return res;
        
    }
};


//累加和法
int maxChunksToSorted(vector<int>& arr) {
	vector<int> res = arr;
	sort(res.begin(), res.end());
	int num = 0;
    long sum1 = 0, sum2 = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		sum1 += res[i];
		sum2 += arr[i];
		if (sum1 == sum2) num++;
	}
	return num;
}
