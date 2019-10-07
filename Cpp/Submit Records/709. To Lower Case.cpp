/********************************************
作者:Alfeim
题目:转换成小写字符
时间消耗:4ms
解题思路:位运算
********************************************/
class Solution {
public:
    string toLowerCase(string str) {
        for(auto &i : str){
            i |= 32;
        }
        return str;  
    }
};
