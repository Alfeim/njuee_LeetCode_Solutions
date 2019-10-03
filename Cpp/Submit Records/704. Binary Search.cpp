/********************************************
作者:Alfeim
题目:二分查找
时间消耗:44ms
解题思路:二分查找
********************************************/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        return find(nums,0,n-1,target);
    }
    
    int find(vector<int>& nums,int low,int high,int target){
        
        if(low >= high) return nums[low] == target ? low : -1;
        
        int mid = (low + high)>>1;
        
        if(nums[mid] == target) return mid;
        
        if(nums[mid]  < target) return find(nums,mid+1,high,target);
        
        return find(nums,low,mid-1,target);

    }
};
