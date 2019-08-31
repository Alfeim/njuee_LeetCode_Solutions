/********************************************
作者:Alfeim
题目:两个字符串的最小ASCII删除和
时间消耗:44ms
解题思路:
DP

dp[i][j]表示长度为i的字符串1和长度为j的字符串2匹配所需要的最小删除和；

当s1[i-1] == s2[j-1]时,显然最后一个字符都不用删除,所以dp[i][j] = dp[i-1][j-1];

否则,要么删除s1的末尾字符,要么删除s2的末尾字符,所以 
dp[i][j] = min(dp[i-1][j] + (int)(s1[i-1]),dp[i][j-1] + (int)(s2[j-1]));

********************************************/
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        dp[0][0] = 0;
        for(int i = 1 ; i <= m ; ++i) dp[i][0] = dp[i-1][0] + (int)(s1[i-1]);
        for(int i = 1 ; i <= n ; ++i) dp[0][i] = dp[0][i-1] + (int)(s2[i-1]);
        
        for(int i = 1 ; i <= m ; ++i){
            for(int j = 1 ; j <= n ; ++j){
                if(s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1];   
                else{
                    dp[i][j] = min(dp[i-1][j] + (int)(s1[i-1]),dp[i][j-1] + (int)(s2[j-1]));
                }
            }
        }

        return dp[m][n];
    }
};
