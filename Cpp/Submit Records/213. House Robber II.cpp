/********************************************
作者:Alfeim
题目:打家劫舍2
时间消耗:0ms
解题思路:动态规划;分两种情况,第一种情况下，状态空间只包括nums[0]......nums[n-1]（即不包含最后一个元素） 
第二种则是nums[1]......nums[n] (即不包含第一个元素)，返回两种情况中的较大者即可
相似题目:198. 打家劫舍   337. 打家劫舍3
********************************************/
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty())
            return 0; 
        if(nums.size() == 1)
            return nums[0];
        vector<int> dp1(nums.size(),0);
        vector<int> dp2(nums.size(),0); 
        dp1[0] = 0,dp2[0] = 0,dp1[1] = nums[0],dp2[1] = nums[1]; 
        for(int i = 2 ; i < nums.size();++i){
            dp1[i] = max(dp1[i-1],nums[i-1] + dp1[i-2]);
        }
        
        for(int i = 2; i < nums.size();++i){
            dp2[i] = max(dp2[i-1],nums[i] + dp2[i-2]);
        }
        
        return max(dp1[nums.size()-1],dp2[nums.size()-1]);
    }
};
