/********************************************
作者:Alfeim
题目:买股票的最佳时机含手续费
时间消耗:120ms
解题思路:DP
其实股票问题都有一个通用的状态表示：

dp[i][j][k]表示到下标i为之,当天允许最大交易次数为j次的情况下,当日是否持有股票的最大利润。

这些股票问题无非是在DP状态上有所化简
********************************************/
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int dp_1 = -prices[0] - fee;
        int dp_0 = 0;
        for(int i = 1; i < n ; ++i){
            int temp = dp_0;
            dp_0 = max(dp_0,dp_1+ prices[i]);       
            dp_1 = max(dp_1,temp - prices[i] - fee);
        }
        return dp_0;
    }
};
