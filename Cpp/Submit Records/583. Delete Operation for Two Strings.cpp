/********************************************
作者:Alfeim
题目:两个字符串的删除操作
时间消耗:20ms
解题思路:动态规划
********************************************/
class Solution {
public:
    int minDistance(string word1, string word2) {
        //等价于寻找最长公共子序列(LCS)问题
        
        int m = word1.size();
        int n = word2.size();

        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i = 1 ; i <= m ; ++i){
            for(int j = 1 ; j <= n ;++j){
                if(word1[i-1] == word2[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return m + n - 2*dp[m][n];
    }
};
