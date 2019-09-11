/********************************************
作者:Alfeim
题目:多米诺和托米诺平铺
时间消耗:8ms
解题思路:DP
dp[i][0]表示到长度i为止,最后一块恰好补齐的情况有多少种方法
dp[i][1]表示到长度i为止,最后一块缺了右下角一个位置有多少种方法
dp[i][2]表示到长度i为止,最后一块缺了右上角一个位置有多少种方法
********************************************/
class Solution {
public:
    int numTilings(int N) {
        vector<vector<long>> dp(N+1,vector<long>(3,0));
        dp[0][0] = 1;
        dp[0][1] = 0;
        dp[0][2] = 0;
        int MOD = pow(10,9) + 7;
        for(int i = 1 ; i <= N ; ++i){
            dp[i][0] = dp[i-1][0]  + dp[i-1][1] + dp[i-1][2] + ( i < 2  ? 0 : dp[i-2][0]); dp[i][0] = (dp[i][0] + MOD)%MOD;
            dp[i][1] = dp[i-1][2]  + (i < 2 ? 0 : dp[i-2][0]); dp[i][1] = (dp[i][1] + MOD)%MOD;
            dp[i][2] = dp[i-1][1]  + (i < 2 ? 0 : dp[i-2][0]); dp[i][2] = (dp[i][2] + MOD)%MOD;
        }
        return dp[N][0];
                
    }
};
