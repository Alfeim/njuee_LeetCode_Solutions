/********************************************
作者:Alfeim
题目:嵌套数组
时间消耗:24ms
解题思路:记忆化搜索
********************************************/
class Solution {
public:
    int res;
    int arrayNesting(vector<int>& nums) {
        res = INT_MIN;
        int n = nums.size();
        vector<int> dp(n,-1);
        for(int i = 0 ; i < n ; ++i){
           if(dp[i] != -1) 
               continue;
           dfs(nums,dp,i);  
        }
        return res;
    }
    
    int dfs(vector<int> &nums,vector<int> &dp,int begin){   
        if(dp[begin] != -1)
            return 0;
        
        dp[begin] = 0;
        dp[begin] = 1 + dfs(nums,dp,nums[begin]);
        res = max(res,dp[begin]);
        return dp[begin];
    }
};
