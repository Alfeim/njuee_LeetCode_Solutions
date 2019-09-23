/********************************************
作者:Alfeim
题目:最长斐波那契子序列的长度
时间消耗:304ms
解题思路:DP
********************************************/
class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A) {
        int n = A.size();
        if(n < 3) return 0;
        
        vector<vector<long>> dp(n,vector<long>(n,0));
        unordered_map<int,int> pos;
        
        for(int i = 0 ; i < n ; ++i) pos[A[i]] = i;    
        
        
        long res = 0; 
        dp[0][1] = 0 ;
        dp[1][2] = A[0] + A[1] == A[2] ? 3 : 0;
        
        for(int j = 3 ; j < n ; ++j){
            for(int i = j - 1; i > 0 ; --i){
                if(pos.count(A[j] - A[i]) && pos[A[j] - A[i]] < i){
                    int last = pos[A[j] - A[i]];
                    dp[i][j] = (dp[last][i] == 0) ? 3 : dp[last][i] + 1; 
                }
                res = max(res,dp[i][j]);
            }
        }
        
        
        return res;
    }
};
