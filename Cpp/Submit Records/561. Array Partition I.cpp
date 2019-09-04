
/********************************************
作者:Alfeim
题目:数组拆分1
时间消耗:4ms
解题思路:排序
********************************************/
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int res = 0;
        for(int i = 0 ; i < n ; i += 2){
            res += nums[i];
        }
        return res;
    }
};
