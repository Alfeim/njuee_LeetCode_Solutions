/********************************************
作者:Alfeim
题目:等差数列划分
时间消耗:4ms
解题思路:动态规划,dp[i]表示以下标i为结尾的等差数列
的最长长度
********************************************/
class Solution {
public:
     int numberOfArithmeticSlices(vector<int>& A) {
         int m = A.size();
         vector<int> dp(m,0);
         int res = 0;
         for(int i = 2 ; i < m ; ++i){
             if(A[i] + A[i-2] == 2*A[i-1])
                 dp[i] = dp[i-1] == 0 ? 3 : dp[i-1] + 1;
             
             if(dp[i] > 0){
                 res += dp[i] - 2;
             }
         }
         
        return res;
         
     }
    
