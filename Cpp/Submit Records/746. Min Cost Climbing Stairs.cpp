/********************************************
作者:Alfeim
题目:使用最小花费爬楼梯
时间消耗:8ms
解题思路:DP
********************************************/
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        
        if(n == 0) return 0;
        if(n <= 2) return cost[n-1];
        
        vector<int> dp(n,0);
        dp[0] = cost[0];
        dp[1] = cost[1];
        
        
        for(int i = 2 ; i < n ; ++i){
            dp[i] = min(cost[i] + dp[i-1],cost[i] + dp[i-2]);
        }
        
        return min(dp[n-1],dp[n-2]);
    }
};
