/********************************************
作者:Alfeim
题目:搜索旋转排序数组
时间消耗:40ms
解题思路:没啥好说的...
********************************************/
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int sum = 0;
        int res = 0;
        int n = nums.size();
        for(int i = 0 ; i < n ; ++i){
            if(nums[i] & 1)
                sum++;
            else{
                res = max(res,sum);
                sum = 0;
            }
        }
        
        res = max(res,sum);
        return res;
    
    }
};
