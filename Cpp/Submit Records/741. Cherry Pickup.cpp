/********************************************
作者:Alfeim
题目:摘樱桃
时间消耗:92ms
解题思路:DP

本题DP思路于常规不同,实际上根据题意,我们可以把这个
问题等价于 “两人同时按照指定规则,一直走到终点时
所能得到的最大回报”

这里同时涉及到步数\第一人的x\第一人的y\第二人的x
\第二人的y 一共五个状态

但是由于在步数确定的情况下只要知道x也就知道y

所以最终只需要3个状态就可以遍历完整的状态空间

dp[step][row1][row2]表示两人都走了从step步的情况下
第一人在row1行,第二人在row2行时开始,走到终点所可得到的最大收益

********************************************/
class Solution {
public:
    int n;
    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();
        if(n == 0) return 0;
        vector<vector<vector<int>>> dp(2*n-1,vector<vector<int>>(n,vector<int>(n,0)));
        dp[2*n - 2][n-1][n-1] = grid[n-1][n-1];
        
        for(int step = 2*n - 3; step >= 0; --step){
            for(int i = n - 1 ; i  >= 0 ; --i){
                for(int j = n - 1 ; j >= 0 ; --j){  
                    if( step - i >= n || step - j >= n || step - i < 0 || step - j < 0) 
                        continue;    
                    
                    if(grid[i][step-i] == -1 || grid[j][step-j] == -1){
                        dp[step][i][j] = -1;
                        continue;
                    }      
                    
                    int tmp1 = ( i + 1 >= n || j + 1 >= n) ? -1 : dp[step + 1][i+1][j+1];
                    int tmp2 = ( step + 1 - i  >= n || step + 1 - j >= n ) ? - 1 : dp[step+1][i][j];
                    int tmp3 = ( i + 1 >= n || step + 1 - j >= n) ? -1 : dp[step+1][i+1][j];
                    int tmp4 = ( step + 1 - i >= n || j + 1 >= n) ? -1 : dp[step+1][i][j+1];
                    int tmp5 = i == j ? grid[i][step-i] : grid[i][step-i] + grid[j][step-j];
                    
                    if(tmp1 == -1 && tmp2 == -1 && tmp3 == -1 && tmp4 == -1) dp[step][i][j] = -1;
                    else dp[step][i][j] = tmp5 + max(max(tmp1,tmp2),max(tmp3,tmp4));    
                  
                }
            }
        }
        

        return dp[0][0][0] == -1 ? 0 : dp[0][0][0];
        
    }
    
  
};
