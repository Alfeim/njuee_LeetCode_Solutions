/********************************************
作者:Alfeim
题目:搜索旋转排序数组的最小值2
时间消耗:4ms
解题思路:二分查找
相似题目：153. 搜索旋转排序数组的最小值
********************************************/
class Solution {
public:
    int findMin(vector<int>& nums) {
        return Solve(0,nums.size()-1,nums);
    }
    
    int Solve(int low , int high, vector<int> &nums){
        int mid = (low + high)/2;
        
        if(low == high)
            return nums[mid];
        
        if(high - low <= 1 && mid > 0 && mid < nums.size() - 1 && nums[mid] <= nums[mid-1] && nums[mid] <= nums[mid+1])
            return nums[mid];
           
        if(nums[low] > nums[high]){
            if(nums[mid] >= nums[low])
                return Solve(mid+1,high,nums);  
            return Solve(low,mid,nums);
        }          
        return min(nums[low],Solve(low+1,high,nums));  
    }
};
