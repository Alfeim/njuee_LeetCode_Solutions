/********************************************
作者:Alfeim
题目:猜数字
时间消耗:4ms
解题思路:二分法;PS:这题翻译真的鬼才
********************************************/
// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        return Solve(1,n);
    }
    
    long Solve(long low,long high){
        long mid = (low + high)/2;
        
        long tmp = guess(mid);
        
        if(tmp == 1)
            return Solve(mid+1,high);
        else if(tmp == -1)
            return Solve(low,mid-1);
        
        return mid;
        
    }
};
