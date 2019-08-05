/********************************************
作者:Alfeim
题目:一和零
时间消耗:156ms
解题思路:DP(二维背包)
********************************************/
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1,vector<int>(n + 1,0));
        int len = strs.size();
        for(int i = 0 ; i < len ; ++i){  
            int zeros = 0;
            int ones = 0;
            for(auto j : strs[i]){
                if(j == '0') zeros++;
                else ones++;
            }    
            for(int V1 = m ; V1 >= zeros ; --V1){
                for(int V2 = n ; V2 >= ones ; --V2){
                    dp[V1][V2] = max(dp[V1][V2],dp[V1-zeros][V2-ones] + 1);
                }
            }   
        }
        return dp[m][n];
    }
};
    
   
