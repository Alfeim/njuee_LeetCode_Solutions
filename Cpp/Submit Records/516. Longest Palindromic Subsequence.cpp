/********************************************
作者:Alfeim
题目:最长回文子序列
时间消耗:112ms
解题思路:DP
********************************************/
class Solution {
public:
    
    int longestPalindromeSubseq(string s) {
        if(s.empty())
            return 0;
        
        int n = s.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        
        for(int i = 0 ; i < n ; ++i){
            dp[i][i] = 1;
            if(i < n - 1) dp[i][i+1] = s[i] == s[i+1] ? 2 : 1;
        }
        
        for(int len = 3 ; len <= n ; ++len){
            for(int i = 0 ; i < n - len + 1 ; ++i){
                int end = i + len - 1;
                dp[i][end] = s[i] == s[end] ? dp[i+1][end-1] + 2 : max(dp[i][end-1],dp[i+1][end]);
            }
        }
        
        return dp[0][n-1];
    }

};
