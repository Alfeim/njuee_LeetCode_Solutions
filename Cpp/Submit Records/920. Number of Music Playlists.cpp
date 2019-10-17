/********************************************
作者:Alfeim
题目:播放列表的数量
时间消耗:0ms
解题思路:DP
********************************************/
class Solution {
public:
    int numMusicPlaylists(int N, int L, int K) {
        //Dynamic Programming
        
        //dp[i][j]表示总共听了i首歌的情况下,且一共有j首不同的歌.对应的播放方法数
        //优化后可以去掉i的维度
        
        long mod = 1000000007;
        vector<long> dp(N+1,0);
        
        dp[1] = N;  
        
        for(int i = 2 ; i <= L ; ++i){
            for(int j = min(i,N) ; j > 0 ; --j){
                //这个转移方程的意义是,如果当前选择的是一首新歌,显然dp[j] = dp[j-1]*(剩余的歌数)
               //否则 就选之前重复的一首歌，因为最后K+1首歌都是不同的，所以可以选j - K 首
                dp[j] = (dp[j-1] * ( N - j + 1) + dp[j] * (j > K ? j - K : 0) + mod) % mod;
            }
        }
        
        return dp[N];
        
    }
};
