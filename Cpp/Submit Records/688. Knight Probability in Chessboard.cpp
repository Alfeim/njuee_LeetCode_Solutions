/********************************************
作者:Alfeim
题目:马在棋盘上的概率
时间消耗:20ms
解题思路:DP
dp[i][j][k]表示从位置[i,j]开始走k步留在棋盘上的概率
********************************************/
class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        double dp[N][N][K+1];
        memset(dp,0,sizeof(dp));
        int pos[8][2]{{1,2},{2,1},{1,-2},{2,-1},{-1,-2},{-2,-1},{-1,2},{-2,1}};
        
        for(int k = 0; k <= K ; ++k){
            for(int i = 0 ; i < N ; ++i){
                for(int j = 0 ; j < N ;++j){
                    if(k == 0) {
                        dp[i][j][k] = 1;
                        continue;
                    }
                    
                    for(auto p : pos){
                        int newi = i + p[0];
                        int newj = j + p[1];
                        if(newi >= 0 && newi < N  && newj >= 0 && newj < N)
                            dp[i][j][k] += 0.125*dp[newi][newj][k-1];
                    }
                    
                }
            }
        }
        
        return dp[r][c][K];
    }
};
