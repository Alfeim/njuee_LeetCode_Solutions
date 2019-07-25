/********************************************
作者:Alfeim
题目:整数替换
时间消耗:12ms
解题思路:递归;剪枝优化
********************************************/
//不剪枝,暴力遍历
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

//剪枝后
/*
用时 0ms,击败100%,在正常递归的基础上进行剪枝优化: 首先取当前数字n的最后一位,如果是0就左移一位,并让记录+1,继续递归; 如果当前数字最后一位是1,则分两种情况:

1.如果当前数字取最后两位恰好等于3,且当前数字大于3,就让当前数字+1

2.否则-1

为什么是3呢?因为3中包含两个连续的1,如果我们对其+1可以保证至少消去2个连续的1,最多在前面的位置增加一个1,所以相当于至少可以消去一个1,这一定是最优解(最坏的情况也只是和减去1的情况等价)

否则,-1肯定要比+1好(-1操作可以保证至少消去一个1)
*/
class Solution {
public:
    int integerReplacement(int n) {
        if(n == INT_MAX)
            return 32;
        
        if( n == 1)
            return 0;
        
        if((n & 1) == 0)
            return 1 + integerReplacement(n >> 1);
        
        int tmp = n & 3;
        if(n > 3 && tmp == 3)
            return 1 + integerReplacement(n + 1);
        
        return 1 + integerReplacement(n-1);
        
    }
};
