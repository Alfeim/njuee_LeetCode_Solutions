/********************************************
作者:Alfeim
题目:最长连续递增序列
时间消耗:4ms
解题思路:没啥好说的..
********************************************/
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.empty()) return 0;
        
        int res = 1,sum = 1;
        int n = nums.size();
        for(int i = 1 ; i < n ; ++i){
            if(nums[i] > nums[i-1]){
                sum++;
            }else{
                res = max(res,sum);
                sum = 1;
            }
        }
        res = max(res,sum);
        return res;
        
    }
};
