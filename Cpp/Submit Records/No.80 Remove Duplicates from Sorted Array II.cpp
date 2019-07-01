/********************************************
作者:Alfeim
题目:删除排序数组中的重复项
时间消耗:24ms
解题思路:双指针(参考STL中的unique、remove函数)
********************************************/
class Solution {
public:
    unordered_map<int,int> dict;
    int removeDuplicates(vector<int>& nums) {
       if(nums.empty())
           return 0;
        
       auto first = nums.begin(),result = nums.begin();
       dict[*result]++;
        
       while(++first != nums.end()){
           if(!(*result == *first) || (*result == *first && dict[*result] < 2)){
               *(++result) = *first;
               dict[*result]++;
           }
       }
        return ++result - nums.begin();
  
    }
};
