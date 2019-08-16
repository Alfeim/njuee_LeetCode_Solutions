/********************************************
作者:Alfeim
题目:有序数组中的唯一单一元素
时间消耗:12ms
解题思路:二分法(时间复杂度要求对数级,不能用按位
异或运算)
********************************************/
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.empty()) return 0;    
        int n = nums.size();
        return Solve(0,n-1,nums);
    }
    
    int Solve(int begin,int end,vector<int> &nums){
        if(begin >= end)
            return nums[begin];
        
        int mid = (begin + end)/2;
        
        if(nums[mid + 1] != nums[mid] && nums[mid-1] != nums[mid])
            return nums[mid];
        
        if( ((end - mid ) & 1) == 0){
            if(nums[mid - 1] == nums[mid])
                return Solve(begin,mid-2,nums);
            return Solve(mid+1,end,nums);
        }
        

        if(nums[mid - 1] == nums[mid])
            return Solve(mid+1,end,nums);
        
        return Solve(begin,mid-1,nums);
    }
    
};
