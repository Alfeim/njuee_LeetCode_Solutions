/********************************************
作者:Alfeim
题目:有序数组中的缺失元素
时间消耗:68ms
解题思路:二分搜索
********************************************/
class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        int n = nums.size();
        return BinarySearch(nums,0,n-1,k);
    }
    
    int BinarySearch(vector<int> &nums,int low,int high,int k){
        
        if(low >= high - 1){
       
            int count1 = nums[low] - nums[0] - low;
            int count2 = nums[high] - nums[0] - high;
            if(count2 < k) return nums[high] + k - count2;
            
            return nums[low] +  k - count1;
        }
        
        int mid = (low + high)>>1;
        int count3 = nums[mid] - nums[0]  - mid;
        
        if(count3 >= k) return BinarySearch(nums,low,mid,k);
        
        return BinarySearch(nums,mid,high,k);
        
    }
};
