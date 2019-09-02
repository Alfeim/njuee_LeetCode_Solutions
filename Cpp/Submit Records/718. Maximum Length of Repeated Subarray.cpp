
/********************************************
作者:Alfeim
题目:最长重复子数组
时间消耗:240ms
解题思路:DP
********************************************/
class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int m = A.size();
        int n = B.size();
        int res = 0;
        vector<vector<int>> dp(m + 1,vector<int>(n + 1,0));
        for(int i = 1 ; i <= m ; ++i){
            for(int j = 1 ; j <= n ; ++j ){
                if(A[i-1] == B[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                 res = max(res,dp[i][j]);
            }
        }
        return res;
    }
};
