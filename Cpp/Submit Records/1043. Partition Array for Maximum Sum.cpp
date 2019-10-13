/********************************************
作者:Alfeim
题目:分隔数组以得到最大和
时间消耗:12ms
解题思路:DP
********************************************/
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        if(A.empty()) return 0;
        
        int n = A.size(),last = 0,tmpMax = 0;  
        vector<int> dp(n,0);
        for(int i = 0  ; i < n ; ++i){
            tmpMax = 0;
            for(int j = i ; j >= 0 && i - j <= K - 1 ; j--){
                tmpMax = max(tmpMax,A[j]);
                last = (j > 0) ? dp[j-1] : 0;
                dp[i] = max(dp[i], last + (i - j + 1) * tmpMax );
            }
        }
        
        return dp[n-1];
    }
};
