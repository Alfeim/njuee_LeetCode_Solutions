/********************************************
作者:Alfeim
题目:搜索旋转排序数组
时间消耗:12ms
解题思路:回溯、二分查找
相似题目：No.33 搜索旋转排序数组
********************************************/
class Solution {
public:
    bool search(vector<int>& nums, int target) {
 
        return Solve(nums,0,nums.size()-1,target);
    }
    bool Solve(vector<int>& nums,int low,int high,int target){
        if(low > high)
            return false;
        
        int mid = (low + high)/2;
        
        if(nums[mid] == target)
            return true;
        
        if(nums[mid] == nums[high])
            return Solve(nums,low,high-1,target);

        if(nums[high] > nums[mid]){
            if(target > nums[mid] && target <= nums[high])
                return Solve(nums,mid+1,high,target);
            
            return Solve(nums,low,mid-1,target);
        }
      
        if(target < nums[mid] && target >= nums[low])
            return Solve(nums,low,mid-1,target);
        
        return Solve(nums,mid+1,high,target);

    }
};
