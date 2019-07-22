/********************************************
作者:Alfeim
题目:组合综合4
时间消耗:4ms
解题思路:dfs会超时,注意,本题每个位置的数其实都可以
在满足“容量”小于指定值的情况下任取,有些类似完全
背包,所以考虑到动态规划;
dp[i]表示目标数为i的情况下所存在的组合总数,我们
可以这样得出转移方程:

遍历数组(已升序排序),相当于我们不断往“背包”里填入当
前元素,如果填入了一个元素,那么我们只需填入剩下的
V-nums[i]的空间就行了;相当于固定当前位置为某个
元素然后继续填充...所以转移方程如下:

dp[i] = dp[i - nums[0]] + dp[i - nums[1]] +...
dp[i - nums[k]]直到nums[k]比i大为止.

注意dp[0] = 1,因为满足容量0只有唯一填法也就是不填

********************************************/
class Solution {
public:
    int res;
    int combinationSum4(vector<int>& nums, int target) {
       sort(nums.begin(),nums.end());
       vector<unsigned long long> dp(target + 1, 0);
       dp[0] = 1;
       int n = nums.size();
       for(int i = 1 ; i <= target ; ++i){
           for(int j = 0 ; j < n && i >= nums[j]; ++j){
               dp[i] += dp[i - nums[j]];
           }
       }
        return dp[target];
    }
  
    
};
