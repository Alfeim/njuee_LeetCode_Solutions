/********************************************
作者:Alfeim
题目:计算各个位数不同的数字个数
时间消耗:4ms
解题思路:递推
********************************************/
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        vector<int> dp(10,0);
        dp[0] = 1;
        dp[1] = 10;
        for(int i = 2;i <= 9;++i){
                dp[i] = dp[i-1] + (dp[i-1]-dp[i-2])*(10-i+1);
        }
        
        return n >= 10 ? dp[9] : dp[n];
    }
};
