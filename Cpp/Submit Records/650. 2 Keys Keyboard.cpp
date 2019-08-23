/********************************************
作者:Alfeim
题目:只有两个键的键盘
时间消耗:28ms
解题思路:DP
********************************************/
class Solution {
public:
    int minSteps(int n) {
        vector<int> dp(n + 1,n);
        dp[1] = 0;
        for(int i = 2 ; i <= n ; ++i){
            int border = i/2;
            for(int j = 1; j <= border ; ++j){
                if(i % j == 0){
                    dp[i] = min(dp[j] + i/j,dp[i]);
                }   
            }
        }
        return dp[n];
        
    }
};
