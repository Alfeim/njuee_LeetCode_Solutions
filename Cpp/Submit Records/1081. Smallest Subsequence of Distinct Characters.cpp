/********************************************
作者:Alfeim
题目:不同字符的最小子序列
时间消耗:0ms
解题思路:栈、贪心算法
********************************************/
class Solution {
public:
    string smallestSubsequence(string text) {
        
        int n = text.size();
        deque<int> S;
        
        string res;
        //visited用于记录目前为止,某个字符是否已存在于res中
        vector<bool> visited(26,false);
        //Mask表示从i位之后的字母掩码，如果某位是1就表示i位(包括i)之后存在该偏移量对应的字母
        vector<int> Mask(n + 1,0);
        
        //初始化掩码
        Mask[n - 1] = 1 << (text[n - 1] - 'a');
        for(int i = n - 2 ; i >= 0 ; i--){
            int offset = text[i] - 'a';
            Mask[i] = Mask[i + 1] | ( 1 << offset);
        } 
        
        
        //从头遍历字符串
        for(int i = 0 ; i < n ; ++i){
            int offset = text[i] - 'a';
           
            //如果该偏移量已经存在就跳过
            if(visited[offset]) continue;
        
            //如果栈顶元素的字典序比当前元素大 且 之后的字符串也有该元素 就删除之
            while(!S.empty() && S.back() > offset && (Mask[i + 1] >> S.back() )  & 1 == 1  ) {
                visited[S.back()] = false;
                S.pop_back();
            }
            
            visited[offset] = true;
            S.push_back(offset);
            
        }
        
        for(auto i : S) res += ('a' + i);
        
        return res;
    }

};
