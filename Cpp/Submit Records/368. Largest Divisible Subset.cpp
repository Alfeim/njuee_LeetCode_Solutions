/********************************************
作者:Alfeim
题目:最大整除子集
时间消耗:52ms
解题思路:动态规划
********************************************/
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        if(n <= 1)
            return nums;
        
        int MaxPos = 0;
        int MaxLen = 0;
        vector<int> res;
        vector<int> dp(n,1);
        vector<int> prev(n,-1);
        dp[0] = 1;
        for(int i = 1 ; i < n; ++i){
            int tmpLen = INT_MIN;
            for(int j = 0; j < i; ++j ){
                if( nums[i] % nums[j] == 0 && dp[j] > tmpLen ){
                        tmpLen = dp[j];
                        prev[i] = j;
                        dp[i] = tmpLen + 1;
                    }
                }
            if(dp[i] > MaxLen){
                MaxPos = i;
                MaxLen = dp[i];    
            }
        } 
        for(int k = MaxPos ; k != -1;){
            res.push_back(nums[k]);
            k = prev[k]; 
        }
        
        reverse(res.begin(),res.end());
        return res;
    }
    
};
