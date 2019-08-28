/********************************************
作者:Alfeim
题目:最长递增子序列的个数
时间消耗:102ms
解题思路:动态规划
********************************************/
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1);
        vector<int> count(n,0);
        int tmpMax = 1;
        int res = n;
        for(int i = 0 ; i < n ; ++i){
            for(int j = 0 ; j < i ; ++j){
                if(nums[i] > nums[j]){
                    dp[i] = max(dp[i],1 + dp[j]);   
                }
            }
            
            for(int j = 0 ; j < i ; ++j){
                if(nums[i] > nums[j] && dp[j] == dp[i] - 1){
                    count[i] += dp[j] == 1 ? 1 : count[j];           
                }
            }
            if(dp[i] > tmpMax) tmpMax = dp[i],res = count[i];
            else if(dp[i] == tmpMax) res += count[i]; 
        }

        return res;
 
    }
};
