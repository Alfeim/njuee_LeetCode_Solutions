/********************************************
作者:Alfeim
题目:地下城游戏
时间消耗:4ms
解题思路:动态规划;注意本体要用逆序;不可用顺序遍历的原因是,在顺
序遍历情况下,未来状态并非取决于当前状态.或者说,如果用dp[i][j]
来代表从起始到到[i,j]为止的最优解,其并不一定包括在经过(i,j)到
达终点(m,l)的最优解中.如果采用倒序,并用dp[i][j]表示从[i,j]到
(m,l)的最优解,那么经过(i,j)的最优解一定包括dp[i][j]。
********************************************/
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        if(dungeon.empty())
            return 1;
        
        int m = dungeon.size()-1;
        int n = dungeon[0].size()-1;
        vector<vector<int>> dp(dungeon.size(),vector<int>(dungeon[0].size(),0));   
        dp[m][n] = dungeon[m][n] <= 0 ? 1 - dungeon[m][n] : 1;
        
        for(int i = n-1 ; i >= 0 ;--i){
            int tmp = dp[m][i+1] - dungeon[m][i];
            dp[m][i] = tmp <= 0 ? 1 : tmp;
        }
        
        for(int i = m-1 ; i >= 0; --i){
            int tmp = dp[i+1][n] - dungeon[i][n];
            dp[i][n] = tmp <= 0 ? 1 : tmp;
        }
        
        for(int i = m - 1 ; i >= 0 ; --i){
            for(int j = n - 1; j >= 0; --j){
                int tmp1 = dp[i][j+1] - dungeon[i][j];
                int tmp2 = dp[i+1][j] - dungeon[i][j];
                tmp1 = tmp1 <= 0 ? 1 : tmp1;
                tmp2 = tmp2 <= 0 ? 1 : tmp2;
                dp[i][j] = tmp1 < tmp2 ? tmp1 : tmp2;
            }
        }

        return dp[0][0]; 
        
    }  
};
