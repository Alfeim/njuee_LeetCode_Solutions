/********************************************
作者:Alfeim
题目:连续的子数组和
时间消耗:64ms
解题思路:累加和性质
********************************************/
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if(nums.empty())
            return false;
        
        int n = nums.size();
        vector<int> Sum(n + 1,0);
        Sum[0] = 0;
        for(int i = 1 ; i <= n ; ++i){
            Sum[i] = Sum[i-1] + nums[i-1];
        }
        
        for(int i = 1 ; i <= n ; ++i){
            for(int j = i + 1 ; j <= n ; ++j){
                int tmp = Sum[j] - Sum[i-1];
                if(tmp == 0 && k == 0) return true;
                if(k != 0 && tmp % k == 0) return true;
            }
        }
        
        return false;
        
        
    }
    

};
