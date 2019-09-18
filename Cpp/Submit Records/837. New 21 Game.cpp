/********************************************
作者:Alfeim
题目:新21点
时间消耗:12ms
解题思路:DP
DP[i]表示从i分开始可以取得胜利(最终分数小于等于N)的概率

显然有DP[i] = 1/W *(dp[i+1] + dp[i+2] .... dp[i + W])
相当于从i分开始的情况下,第一步能够取1-W分,而且概率均为
1/W，故推出这个状态方程

但是仔细观察DP[i]和DP[i+1]我们可以发现

DP[i] = DP[i+1] + 1/W * (dp[i+1] - dp[i + W + 1])
所以可以在O(1)的时间内取得DP[i]的值

********************************************/

class Solution {
public:
    double new21Game(int N, int K, int W){
        int border = K - 1 + W;
        if(K == 0) return 1.0;
        
        vector<double> dp(border + 1,0.0);
        
        for(int i = K ;  i <= N ; ++i ) dp[i] = 1.0;
        
        double S = min(N-K+1,W); //S表示初始的分子 即从K---N分内都是合法的
        for(int i = K - 1 ; i >= 0 ; --i){
            dp[i] = S/W;
            S += dp[i] - dp[i + W];
        }
        
        return dp[0];
    }
};
