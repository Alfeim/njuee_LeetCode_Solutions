/********************************************
作者:Alfeim
题目:平方数之和
时间消耗:0ms
解题思路:双指针
********************************************/
class Solution {
public:
    bool judgeSquareSum(int c) {
        int border = sqrt(c);
        for(int left = 0 ,right = border + 1;left <= right;){
            long sum = (long)pow(left,2) + (long)pow(right,2);
            if(sum > c) right--;
            else if(sum < c) left++;
            else return true;
        }
        return false;
    }
    
    
};
