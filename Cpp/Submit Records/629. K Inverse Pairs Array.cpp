/********************************************
作者:Alfeim
题目:K个逆序对数组
时间消耗:76ms
解题思路:DP
dp[i][j]表示到下标i为止,包含了多少个k个逆序对的数组的
排列方式

注意,为了防止出现负数,在取模时要先加上模的值
********************************************/
class Solution {
public:
    int kInversePairs(int n, int k) {
        vector<int> most(1+n,0);
        most[1] = 0;
        long long basic = 1000000007;
        for(int i = 2 ; i <= n ; ++i) most[i] = most[i-1] + i - 1;
        vector<vector<long long>> dp(n+1,vector<long long>(k+1,0));
        dp[1][0] = 1;
        for(int i = 2 ; i <= n ; ++i){
            for(int j = 0 ; j <= k && j <= most[i]; ++j){
                long long tmp1 = j > 0 ? dp[i][j-1] : 0;
                long long tmp2 = j - i >= 0 ?dp[i-1][j-i] : 0;
                dp[i][j] = (dp[i-1][j] + tmp1 - tmp2 +basic)%basic;
            }
        }
        return (int)dp[n][k]; 
    }
};
