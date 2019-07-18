/********************************************
作者:Alfeim
题目:4的次幂
时间消耗:4ms
解题思路:移位法
********************************************/
class Solution {
public:
    bool isPowerOfFour(int num) {
        long tmp = 1;
        while(tmp <= num){
            if(tmp == num)
                return true;
            tmp <<= 2;
        }      
        return false;
    }
};
