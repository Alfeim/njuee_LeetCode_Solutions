/********************************************
作者:Alfeim
题目:出界的路径数
时间消耗:16ms
解题思路:动态规划
********************************************/
class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        long dp[m][n][N+1];
        memset(dp,0,sizeof(dp));
        for(int step = 1 ; step <= N ; ++step){
            for(int rows = 0 ; rows < m ; ++rows){
                for(int cols = 0 ; cols < n ; ++cols){
                    if(rows == 0) dp[rows][cols][step]++;
                    if(rows == m - 1) dp[rows][cols][step]++;
                    if(cols == 0) dp[rows][cols][step]++;
                    if(cols == n - 1) dp[rows][cols][step]++;
                    if(rows - 1 >= 0) dp[rows][cols][step] += dp[rows-1][cols][step-1];
                    if(rows + 1 < m) dp[rows][cols][step] += dp[rows+1][cols][step-1];
                    if(cols - 1 >= 0) dp[rows][cols][step] += dp[rows][cols-1][step-1];
                    if(cols + 1 < n) dp[rows][cols][step] += dp[rows][cols+1][step-1];
                    dp[rows][cols][step] %= 1000000007;
                }
            }
        }
        
        return dp[i][j][N];
    }
};
