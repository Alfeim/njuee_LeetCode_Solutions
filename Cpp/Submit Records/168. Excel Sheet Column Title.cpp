/********************************************
作者:Alfeim
题目:Excel列表名称
时间消耗:12ms
解题思路:本质就是26进制计算
********************************************/
class Solution {
public:
    string convertToTitle(int n) {
        string res;  
        while(n > 0){
            char word = 'A' + (n-1)%26;
            res = word + res;
            n = (n-1)/26;
        }       
        return res;
    }
};
