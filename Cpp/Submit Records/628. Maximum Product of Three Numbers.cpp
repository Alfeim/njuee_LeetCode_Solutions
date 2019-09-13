/********************************************
作者:Alfeim
题目:三个数的最大乘积
时间消耗:84ms
解题思路:数学
********************************************/
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        
        //无论有多少正数或者负数,首先一定会选择最大数即nums[n-1],然后无非就是选择开头两位还是倒数两位 
        return max(nums[0]*nums[1]*nums[n-1],nums[n-3]*nums[n-2]*nums[n-1]);
        
    }
};
