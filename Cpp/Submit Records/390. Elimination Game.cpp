/********************************************
作者:Alfeim
题目:消除游戏
时间消耗:12ms
解题思路:找规律
********************************************/
class Solution {
public:
    int lastRemaining(int n) {
        if(n == 1)
            return 1;
     
        int last = 2,exp = 0,left = n/2,count = 0;
        
        while(left > 1){
            count++;
            exp++;
            
            if(count % 2 == 0 || left % 2 != 0)
                last += pow(2,exp);
            
            left /= 2;
        }
        return last;

    }
};
