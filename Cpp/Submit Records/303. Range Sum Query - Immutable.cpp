/********************************************
作者:Alfeim
题目:区域和检索-数组不可变
时间消耗:44ms
解题思路:动态规划,用dp[i]表示到i为止的和,要求
[i,j]区间的和只要用dp[j] - dp[i-1]
********************************************/
class NumArray {
public:
    vector<int> tmp;
    vector<int> dp;
    NumArray(vector<int>& nums):tmp(nums),dp(nums.size() + 1,0){
        dp[0] = 0;
        for(int i = 1 ; i <= tmp.size(); ++i){
            dp[i] = tmp[i-1] + dp[i-1];    
        }
    }
    
    int sumRange(int i, int j) {
        return dp[j+1] - dp[i];
    }
};
