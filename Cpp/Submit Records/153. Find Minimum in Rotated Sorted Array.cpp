/********************************************
作者:Alfeim
题目:寻找旋转排列数组的最小值
时间消耗:4ms
解题思路:二分查找
相似题目：154. 寻找旋转排列数组的最小值2
********************************************/
class Solution {
public:
    int findMin(vector<int>& nums) {        
         return Solve(0,nums.size()-1,nums);
    }
    
    int Solve(int low,int high,vector<int>& nums){
        int mid = (low + high)/2;
        
        if(low == high)
            return nums[mid];

        if(mid < nums.size() - 1 && mid > 0 && nums[mid] < nums[mid-1] && nums[mid] < nums[mid+1])
            return nums[mid];
        
        if(nums[low] > nums[high]){
            if(nums[mid] < nums[low])
                return Solve(low,mid-1,nums);
            
            return Solve(mid+1,high,nums);
       }  
        return nums[low];
    }
    
    
};
