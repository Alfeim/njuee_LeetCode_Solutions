/********************************************
作者:Alfeim
题目:骑士拨号器
时间消耗:112ms
解题思路:利用枚举将二维数组压缩为一维,枚举后进行DP
********************************************/
class Solution {
public:
    int knightDialer(int N) {
        vector<vector<int>> dst{{4,6},{6,8},{7,9},{4,8},{0,3,9},{},{0,1,7},{2,6},{1,3},{2,4}};
        vector<vector<long>> dp(10,vector<long>(N,1));
        long mod = 1000000007;
        
        
        for(int i = 1 ; i < N ; ++i){
            for(int j  =  0 ; j <= 9 ; ++j){
                dp[j][i] = 0;
                for(auto d : dst[j]){
                    dp[j][i] = (dp[j][i] + dp[d][i-1] + mod)%mod;     
                }
            }
        }
        
        
        long res = 0;
        for(int i = 0 ; i < 10 ; ++i){
            res = (res + dp[i][N-1] + mod)%mod;
        }
        
        return res;
 
    }
};
