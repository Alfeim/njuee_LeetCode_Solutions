/********************************************
作者:Alfeim
题目:交换一次的先前序列
时间消耗:12ms
解题思路:136ms

思路和“寻找下一个排列”的思想有些类似 只不过这里限定了交换次数为1次(而寻找下一排列需要交换后排序)

从数组末尾开始向前遍历 寻找第一个“上坡”

然后从“上坡”末端开始搜索，如果右侧存在比当前元素小的、最近的最大元素，就交换之
********************************************/
class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& A) {
        int n = A.size();
        if(n == 0) return A;
        
        vector<int> minRight(n,10001);
        int tmp = A[n-1];
        
        for(int i = n - 2 ; i >= 0 ; --i){
            minRight[i] = tmp;
            tmp = min(tmp,A[i]);
        }
        
        
        //寻找第一个“上坡”
        int i = n - 1;
        
        while(i > 0 && A[i] >= A[i-1]) i--;
        
        if(i == 0) return A;
        
        
        //开始遍历“上坡”
        while(i > 0  && A[i] < A[i-1] && minRight[i] >= A[i]) i--;
        
        
        //开始寻找离交换位置最近的、小于它的最大数
        int pos = i + 1,tmp_pos = i + 1,Max = A[i+1];
        
        while(tmp_pos < n){
            
            if(A[tmp_pos] < A[i] && A[tmp_pos] > Max) {
                pos = tmp_pos;
                Max = A[tmp_pos];
            }
            
            tmp_pos++;
        }
            
        swap(A[i],A[pos]);
        
        return A;
        
    }
};
