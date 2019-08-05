/********************************************
作者:Alfeim
题目:用rand7()实现rand10()
时间消耗:108ms
解题思路:拒绝采样
********************************************/
// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int tmp = rand7();
        while(tmp > 5) tmp = rand7();
        
        int tmp2 = rand7();
        while(tmp2 == 7) tmp2 = rand7();
        
        if(tmp2 <= 3) return tmp;
        
        return tmp + 5;
    }
};
