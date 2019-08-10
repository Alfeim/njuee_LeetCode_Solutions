/********************************************
作者:Alfeim
题目:零钱兑换2
时间消耗:4ms
解题思路:完全背包-DP
********************************************/
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1,0);
        int n = coins.size();
        int res = 0;
        dp[0] = 1;
        for(int i = 0 ; i < n ; ++i){
            for(int V = 0 ; V <= amount ; ++V){
                 if(V >= coins[i]){
                    dp[V] = dp[V] + dp[V - coins[i]];
                 }
            }
        }
        
        return dp[amount];

    }
};
