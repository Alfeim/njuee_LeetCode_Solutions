/********************************************
作者:Alfeim
题目:丑数
时间消耗:4ms
解题思路:循环除以2、3、5的因子,看最后结果是否为1
********************************************/
class Solution {
public:
    bool isUgly(int num) {
        while(num > 0 && num % 2 == 0){
            num /= 2;
        }
        
        while(num > 0  &&num % 3 == 0){
            num /= 3;
        }
        
        while(num > 0 && num % 5 == 0){
            num /= 5;
        }   
        return num == 1;

    }
};
