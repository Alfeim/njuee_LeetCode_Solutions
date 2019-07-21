/********************************************
作者:Alfeim
题目:有效的完全平方数
时间消耗:4ms
解题思路:二分法
********************************************/
class Solution {
public:
    bool isPerfectSquare(int num) {
        return Solve(num,0,num);
    }
    
    bool Solve(int num,int low,int high){
        int mid = (low + high)/2;
        
        if(low > high)
            return false;
        long number = (long)mid * (long)mid;
        
        if(number > num)
            return Solve(num,low,mid-1);
        else if(number < num)
            return Solve(num,mid+1,high);
        return true;
        
    }
};
