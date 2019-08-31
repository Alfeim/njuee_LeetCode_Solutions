/********************************************
作者:Alfeim
题目:乘积小于K的子数组
时间消耗:120ms
解题思路:
双指针法,每次先移动right指针,直到累计乘积大于等于k,此时让结果加上左右指针间的距离
然后每次循环都让左指针+1,表示以left指针开头的所有合理区间
********************************************/
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1) return 0; 
        int n = nums.size();
        int res = 0;
        int multi = 1,left = 0,right = -1;
        
        while(left < n){
            while(right < n && multi < k){
                right++;
                if(right < n) multi *= nums[right];
            }
            res += right - left;
            multi /= nums[left++];
            while(right >= left && multi >= k ) multi /= nums[right--]; 
        }
        
        return res;
    }
};
