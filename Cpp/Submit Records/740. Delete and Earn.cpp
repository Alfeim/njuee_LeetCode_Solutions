/********************************************
作者:Alfeim
题目:删除与获得点数
时间消耗:8ms
解题思路:DP
两种思路，直接DP或转换成打家劫舍问题再DP
********************************************/

//直接DP
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        if(nums.empty()) return 0;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        //dp用于存储到下标i为止的最大点数
        vector<int> dp(n,0);
        //start_pos存储数字i的起始位置
        vector<int> start_pos(10000,0);
        
        
        int last = 0;
        for(int i = 0 ; i < n ; ++i){
            if(nums[i] != last) start_pos[nums[i]] = i;
            last = nums[i];
        }
        
        dp[0] = nums[0];
        int tmp_number = 0,tmp_pos = 0,last_number = 0,last_pos = 0;
        for(int i = 1 ; i < n ; ++i){
            if(nums[i] > 1 + nums[i-1]){
                
                dp[i] = dp[i-1] + nums[i];
                
            }else if(nums[i] == 1 + nums[i-1]){
                
                last_number = nums[i-1];
                last_pos = start_pos[last_number];
                dp[i] = max(nums[i] + (last_pos > 0 ? dp[last_pos-1] : 0),dp[i-1]);
                
            }else if(nums[i] == nums[i-1]){
                
                if(start_pos[nums[i]] == 0){
                    dp[i] = (i + 1)*nums[i];
                }else{
                    tmp_number = nums[i];
                    tmp_pos = start_pos[nums[i]];
                    last_number = nums[tmp_pos - 1];
                    last_pos  = start_pos[last_number];   
                    if(tmp_number - 1 > last_number) 
                        dp[i] = dp[i-1] + nums[i];
                    else{
                        int tmp1 = (i - tmp_pos + 1) * tmp_number + ( last_pos > 0 ? dp[last_pos - 1] : 0); 
                        int tmp2 =  dp[tmp_pos - 1];
                        dp[i] = max(tmp1,tmp2);
                    } 
                }
            }
        }

        return dp[n-1];
        
    }
};

//转换成打家劫舍问题
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        if(nums.empty()) return 0;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int> records;
        vector<int> newnums;
        int last = 0;
        records.push_back(nums[0]);
        for(int i = 0 ; i < n ; ++i){
            if(i > 0 &&  nums[i] != nums[i-1]){
                records.push_back(nums[i]);
                newnums.push_back(last);
                last = 0;
            }
            last += nums[i];
        }
        
        records.push_back(nums[n-1]);
        newnums.push_back(last);
        n = newnums.size();
        
        vector<int> dp(n,0);
        dp[0] = newnums[0];
        for(int i = 1 ; i < n ; ++i){
            if( records[i-1] < records[i] - 1 )
                dp[i] = dp[i-1] + newnums[i];
            else
                dp[i] = max(newnums[i] + (i <= 1 ? 0 : dp[i-2]) , dp[i-1]);
        }
        return dp[n-1];
        
    }
};
