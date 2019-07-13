/********************************************
作者:Alfeim
题目:第一个错误的版本
时间消耗:0ms
解题思路:二分搜索
********************************************/
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        return Solve(1,n);
    }
    
    int Solve(long low ,long high){
        long mid = (low + high)/ 2;
        
        if(low >= high)
            return mid;
        
        if(!isBadVersion(mid))
            return Solve(mid+1,high);
        
        return Solve(low,mid);
        
    }
    
};
