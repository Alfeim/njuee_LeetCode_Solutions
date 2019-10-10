/********************************************
作者:Alfeim
题目:两个非重叠子数组的最大和
时间消耗:4ms
解题思路:DP
********************************************/
class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        //分两种大情况 1.M长度的数组在后 2.M长度的数组在前
        
        //先求前缀和方便计算
        int n = A.size();
        
        if(n == 0 || n < L + M ) return 0;
        
        vector<int> sum(n+1,0);
        for(int i = 0 ; i < n ; ++i) sum[i+1] = sum[i] + A[i];
        
        if(n == L + M) return sum[n];
        
        /******然后计算M长度的数组在后的情况,dp1[i]表示到下标i为止,最大的长度为L的连续数组元素和*****/
        int res1 = 0;
        vector<int> dp1(n,0);
        //初始状态从下标i = L - 1开始,因为至少要满足前面子串长为L
        dp1[L - 1] = sum[L] - sum[0];
        
        for(int i = L ; i < n ; ++i) dp1[i] = max(dp1[i-1],sum[i + 1] - sum[i + 1 - L]);
        for(int i = L + M  - 1 ; i < n ; ++i){
            res1 = max(dp1[i - M] + sum[i + 1] - sum[i + 1 - M] ,res1);
        }
        
        /******然后计算M长度的数组在前的情况,dp2[i]表示到下标i为止,最大的长度为M的连续数组元素和*****/
        int res2 = 0;
        vector<int> dp2(n,0);
        //初始状态从下标i = M - 1开始,因为至少要满足前面子串长尾M
        dp2[M - 1] = sum[M] - sum[0];
        
        for(int i = M ; i < n ; ++i) dp2[i] = max(dp2[i-1],sum[i+1] - sum[i + 1 - M]);
        for(int i = L + M - 1; i < n ; ++i){
            res2 = max(dp2[i - L] + sum[i + 1] - sum[i + 1 - L], res2);
        }
        
        //返回两种情况下最大的
        return max(res1,res2);
        
    }
};
