/********************************************
作者:Alfeim
题目:水壶问题
时间消耗:4ms
解题思路:实际就是求最大公约数-z如果可以被x和y的最大
公约数整除即返回true;这里使用辗转相除法
********************************************/
class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if(z == 0)
            return true;
        
        if(x + y < z)
            return false;
        
        if(x  <  y)
            swap(x,y);
        
        if(y > 0){
            int r = x % y;
            while(r > 0){
                x = y;
                y = r;
                r = x % y;
            }
            return z % y == 0;
        }
        
        return z % x == 0;
    }
};
