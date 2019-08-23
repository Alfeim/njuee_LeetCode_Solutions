/********************************************
作者:Alfeim
题目:完美数
时间消耗:4ms
解题思路:没啥好说的..
********************************************/
class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num <= 0)
            return false;
        
        int border = sqrt(num);
        int res = 0;
        for(int i = 1 ; i <= border ; ++i){
            if(num % i != 0) continue;
            res += i + num/i;
        }
        
        if(num == border * border) res -= border;
        res -= num;
        
        return res == num;
        
    }
};
