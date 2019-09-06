/********************************************
作者:Alfeim
题目:最大加号标志
时间消耗:152ms
解题思路:双向DP
********************************************/
class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        int res = 1;
        vector<vector<int>> MAP(N,vector<int>(N,1));
        
        int dp[N][N][4] = {0};   //0 = 上     1 = 下    2 = 左   3 = 右
        if(mines.size() >= pow(N,2)) return 0;    
        for(auto i : mines){
            MAP[i[0]][i[1]] = 0;
        }
    
        //预处理
        if( MAP[0][0] == 1){
            dp[0][0][0] = 1;
            dp[0][0][2] = 1;
        }
        
        if( MAP[N-1][0] == 1){
            dp[N-1][0][2] = 1;
            dp[N-1][0][1] = 1;
        }
        
        if( MAP[0][N-1] == 1){
            dp[0][N-1][3] = 1;
            dp[0][N-1][0] = 1;
        }
        
        if( MAP[N-1][N-1] == 1){
            dp[N-1][N-1][1] = 1;
            dp[N-1][N-1][3] = 1;
        }

        for(int i = 1 ; i < N - 1 ; ++i){
            dp[0][i][0] = MAP[0][i] == 0 ? 0 : 1;
            dp[N-1][i][1] = MAP[N-1][i] == 0  ? 0 : 1;
            dp[i][0][2] = MAP[i][0] == 0 ? 0 : 1;
            dp[i][N-1][3] = MAP[i][N-1] == 0 ? 0 : 1;
        }
        
        //先自左上到右下
        for(int i = 1 ; i < N - 1; ++i){
            for(int j = 1 ; j < N - 1 ; ++j){
                if(MAP[i][j] == 0 ) continue;
                dp[i][j][0] = 1 + dp[i-1][j][0];
                dp[i][j][2] = 1 + dp[i][j-1][2];
            }
        }
        
        //然后自右下到左上
        for(int i = N-2 ; i > 0 ; --i){
            for(int j = N-2 ; j > 0 ; --j){
                if(MAP[i][j] == 0 ) continue;
                dp[i][j][1] = 1 + dp[i+1][j][1];
                dp[i][j][3] = 1 + dp[i][j+1][3];
                res = max(res,min(min(dp[i][j][0],dp[i][j][1]),min(dp[i][j][2],dp[i][j][3])));
            }
        }
    
        return res;
        
    }
};
