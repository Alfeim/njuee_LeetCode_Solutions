/********************************************
作者:Alfeim
题目:投掷骰子的N种方法
时间消耗:12ms
解题思路:DP
状态dp[i][j]表示i个色子掷出j共有多少情况

则有转移方程 ： dp[i][j] = sum(dp[i-1][j-last]);

我们发现当前状态(i)仅仅与上一时刻的状态(i-1)有关，因此可以通过倒序遍历j的方式将空间消耗优化为1维度
********************************************/
class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        long maxtarget = d * f;
        
        if(target == maxtarget) return 1;

        if(target > maxtarget) return 0;
        
        vector<long> dp(target + 1,0);
        long mod = 1000000007;
        long tmp = 0;

        dp[0] = 1;

        for(int i = 1 ; i <= d ; ++i){

            for(int j = target; j >= i ; --j){

                tmp = 0;
                for(int last = 1 ; last <= j - i + 1&& last <= f ; ++last){
                    tmp += dp[j-last];
                    tmp %= mod;
                }
                dp[j] = tmp;
            }
        }
        
        return dp[target];
    }
};
