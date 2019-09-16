/********************************************
作者:Alfeim
题目:最大平均值和的分组
时间消耗:28ms
解题思路:DP
dp[i][k]表示到下标i为止,分割为k+1个数组的情况
下的最大和
********************************************/
class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        int n = A.size();
        
        vector<int> sum(n,0);
        sum[0] = A[0];
        for(int i = 1 ; i < n ; ++i) sum[i] = sum[i-1] + A[i]; 
        
        vector<vector<double>> dp(n,vector<double>(K,0.0));
        
        for(int i = 0 ; i < n ; ++i){
            dp[i][0] = (double)sum[i]/(i+1);
        }
        
        int tmpSum = 0;
        double last = 0.0;
        double cur = 0.0;
        for(int i = 1 ; i < n ; ++i){
            int border = min(K - 1,i);
            for(int k = 1 ; k <= border ; ++k){
                for(int l = i ; l >= 0 ; --l){
                    tmpSum = sum[i] - ( l > 0 ? sum[l-1] : 0);
                    last = l > 0 ? dp[l-1][k-1] : 0.0; 
                    double cur = (double)(tmpSum)/(i-l+1) + last;     
                    dp[i][k] = max(cur,dp[i][k]);
                }
            }               
        }
        
        return dp[n-1][K-1];
    }
};
