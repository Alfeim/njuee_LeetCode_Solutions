/********************************************
作者:Alfeim
题目:最优除法
时间消耗:0ms
解题思路:只需要让分子最大,分母最小即可...
也就是在第二个数和最后一个数两边加上括号...
********************************************/
class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
            return "";
        
        if(n == 1)
            return to_string(nums[0]);
        
        if(n == 2)
            return to_string(nums[0]) + "/" + to_string(nums[1]);
        
   
        string fz = to_string(nums[0]);
        string fm;

        for(int i = 1 ; i < n ; ++i){
            if(i == 1)
                fm += "/(" + to_string(nums[i]);
            else if(i != n - 1)
                fm += "/" + to_string(nums[i]);
            else 
                fm += "/" + to_string(nums[i]) + ")";
        }
        
        return fz + fm;
        
    }
};
