/********************************************
作者:Alfeim
题目:火柴拼正方形
时间消耗:100ms
解题思路:dfs
********************************************/
class Solution {
public:
    int target;
    bool makesquare(vector<int>& nums) {
        if(nums.empty())
            return false;

        
        int sum = 0;
        sort(nums.begin(),nums.end(),greater<int>());
        for(auto i : nums)
            sum += i;
        
        target = sum/4;
        if(sum % 4 != 0) return false;
                
        vector<int> sides(4,0);
        return Solve(nums,sides,0);
        
    }
    
    bool Solve(vector<int> &nums,vector<int> &sides,int pos){
        if(pos == nums.size()){
            return (sides[0] == sides[1] && sides[0] == sides[2] && sides[0] == sides[3]);
        }
        
        if(nums[pos] > target)
            return false;
        
        for(int i = 0 ; i < 4 ; ++i){
            if(sides[i] == target || sides[i] + nums[pos] > target)
                continue;
            
            sides[i] += nums[pos];
            if(Solve(nums,sides,pos+1))
                return true;
            sides[i] -= nums[pos];
        }
        return false;  
    }

};
