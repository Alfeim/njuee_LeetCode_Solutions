/********************************************
作者:Alfeim
题目:整数替换
时间消耗:12ms
解题思路:递归
********************************************/
class Solution {
public:
    int integerReplacement(int n) {
        if(n == INT_MAX)
            return 32;
        
        if( n == 1)
            return 0;
        
        if((n & 1) == 0)
            return 1 + integerReplacement(n >> 1);
        
        return 1 + min(integerReplacement(n -1),integerReplacement(n + 1));
        
    }
};
