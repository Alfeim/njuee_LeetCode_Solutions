/********************************************
作者:Alfeim
题目:K站中转最便宜的航班
时间消耗:12ms
解题思路:DP
dp[i][K]表示从起始地到达i地,最多中转K次的最小费用

有转移方程,l表示所有可达i的站点
dp[i][K] = min(dp[i][K],dp[l][K-1] + cost(l,i))
********************************************/

class Solution {
public:
    unordered_map<int,unordered_map<int,int>> edges;
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        //动态规划
        
        vector<vector<int>> dp(n,vector<int>(K+1,INT_MAX));
        
        for(auto i : flights) {
            if(i[0] == src){
                dp[i[1]][0] = i[2];
            }
        }
        
        for(int i = 0; i <= K; i++) dp[src][i] = 0;
        
        
        for(int k = 1; k <= K; k++){
            for(auto i : flights){
                if(dp[i[0]][k - 1] != INT_MAX){
                    dp[i[1]][k] = min(dp[i[1]][k], dp[i[0]][k - 1] + i[2]);
                }
            }
        }
        
        return dp[dst][K] == INT_MAX ? -1: dp[dst][K];
    }
    
 
};



