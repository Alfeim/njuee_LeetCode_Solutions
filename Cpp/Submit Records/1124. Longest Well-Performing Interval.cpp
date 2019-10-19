/********************************************
作者:Alfeim
题目:表现良好的最长时间段
时间消耗:24ms
解题思路:
记录“前缀和”，用如果遇到超过8小时 就让前缀和 + 1，否则 - 1;
如果两段前缀和之差大于0，证明这两个前缀和之间的区间是满足“表现良好”的要求的
那么就转换为了最大上坡问题
********************************************/
class Solution {
public:
    int longestWPI(vector<int>& hours) {
        stack<int> S;
        int n = hours.size();
        int res = 0;
        
        vector<int> prefix(n+1,0);
        for(int i = 0 ; i < n ; ++i) prefix[i + 1] = prefix[i] + (hours[i] > 8 ? 1 : -1);
        
        for(int i = 0 ; i <= n ; ++i){
            if( S.empty() || prefix[i] < prefix[S.top()] ) S.push(i);
        }
        
        for(int i = n ; i >= 0 ; --i){
            
            int last = i;
            
            if(!S.empty() && S.top() >= i) S.pop();
            
            while(!S.empty() && prefix[S.top()] < prefix[i]){
                last = S.top();
                S.pop();
            }
            
            res = max(res, i - last);
        }
        
        return res;

    }
};
