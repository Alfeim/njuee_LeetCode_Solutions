/********************************************
作者:Alfeim
题目:只出现一次的数字3
时间消耗:4ms
解题思路:先遍历一遍进行按位异或运算.得到结果后,从结果的低位到高位寻找第一个"1",其代表两个数中
第一次出现“不同”的位,然后将结果除该位外全部置零,得到一个mask;
再遍历一次数组,所有和mask相与为0的存在一个变量,为1的存在另一个变量,再执行一遍按位异或,最终
两个变量即对应两个数
https://blog.csdn.net/qq_38595487/article/details/81163737
********************************************/
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> res(2);
        int sum = nums[0];
        for(int i = 1; i < nums.size();++i){
            sum ^= nums[i];
        }
        
        int flag = sum & (~(sum-1));
        
        for(auto i : nums){
            if( (i & flag) == 0)
                res[0] ^= i;
            else
                res[1] ^= i;
        }
        return res;
        
    }
};
