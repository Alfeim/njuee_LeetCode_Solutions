/********************************************
作者:Alfeim
题目:数字的补数
时间消耗:4ms
解题思路:没啥好说的...
********************************************/
class Solution {
public:
    int findComplement(int num) {
        int tmp = num;
        long sum = 1;
        while(tmp > 0){
            sum <<= 1;
            tmp >>= 1;
        }
        sum -= 1;
        return sum - num; 
        
    }
};
