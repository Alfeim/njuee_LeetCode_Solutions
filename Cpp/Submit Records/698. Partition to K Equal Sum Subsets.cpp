/********************************************
作者:Alfeim
题目:划分为k个相同的子集
时间消耗:8ms
解题思路:

两种回溯思路

1.按顺序遍历所有数,选择某个子集填入该数，会超时

2.按顺序遍历所有子集,每次都再选与不选该数填入本子集做选择
********************************************/

//第一种代码
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        
        int Max = 0;
        int sum = 0;
        for(auto i : nums){
            Max = max(i,Max);
            sum += i;
        }
        if(sum % k != 0 ) return false;
        
        int target = sum/k; 
        if(Max > target) return false;
        vector<int> tmp(k,0);
        return Solve(0,nums,tmp,target);
    }
    
    bool Solve(int pos,vector<int>& nums,vector<int> &tmp,int target){
        if(pos == nums.size()){
            for(auto i : tmp) if(i != target) return false;
            return true;
        }
        
        for(auto &i : tmp){
            if(i + nums[pos] <= target){
                i += nums[pos];
                if(Solve(pos+1,nums,tmp,target)) return true;
                i -= nums[pos];
            }
        }
        
        return false;
    }
    
};


//第二种

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        int Max = 0;
        for(auto i : nums){
            Max = max(i,Max);
            sum += i;
        }
        
        if(sum % k != 0 ) return false;
        int target = sum/k; 
        if(Max > target) return false;
        int n = nums.size();
        vector<bool> visited(n,0);
        return Solve(0,nums,visited,target,k,0);
    }
    
    bool Solve(int pos,vector<int>& nums,vector<bool> &visited,int target,int k,int sum){
        if(k == 0){
           return true;
        }
        
        if(sum == target)
            return Solve(0,nums,visited,target,k-1,0);
            
        int n = nums.size();
        for(int i = pos ; i < n ; ++i){
            if(!visited[i] && sum + nums[i] <= target){
                visited[i] = true;
                if(Solve(i+1,nums,visited,target,k,sum + nums[i])) return true;
                visited[i] = false;
            }
        }

        return false;        
    }
    
};



