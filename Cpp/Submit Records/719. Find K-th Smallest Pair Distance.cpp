/********************************************
作者:Alfeim
题目:找到第K小的距离对
时间消耗:32ms
解题思路:二分 + 双指针法
********************************************/
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int low = 0;
        int high = nums.back() - nums[0];
        
        while(low < high){
            int mid = (low + high)>>1;
            int count = 0 , left = 0;
            for(int right = 0 ; right < n ; ++right){
                while(nums[right] - nums[left]  > mid) left++;
                count += right - left;
            }
            if(count >= k) high = mid;
            else low = mid + 1;
        }
        
        return low; 
    }
};


