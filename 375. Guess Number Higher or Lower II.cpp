/********************************************
作者:Alfeim
题目:猜数字的大小
时间消耗:16ms
解题思路:动态规划;dp[i][j]表示从i位置开始到j位置
的范围内,猜对数字所需要的保底金额;实际上,每次都可以从
中间位置开始遍历(不难看出规律)进行优化
********************************************/
class Solution {
public:
    int getMoneyAmount(int n) {
       vector<vector<int>> dp(n+1,vector<int>(n+1,0));
       for(int size = 2; size <= n ; size++){
           for(int begin = 1 ; begin <= n - size + 1 ; begin++){
               int res = INT_MAX;
               for(int j = begin + (size - 1)/2 ; j < begin + size - 1;++j){
                    int tmp = j + max(dp[begin][j-1],dp[j+1][begin + size -1]);
                    res = min(res,tmp);
               }
               dp[begin][begin+size-1] = res;
           }
       }
        
        return dp[1][n];
    
    }
};
