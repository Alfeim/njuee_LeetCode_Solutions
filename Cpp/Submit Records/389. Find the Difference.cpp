/********************************************
作者:Alfeim
题目:找不同
时间消耗:0ms
解题思路:先扫描t,累加每个字符的值,然后扫描s,递减每个
位置的值,最后答案也就是所求的唯一不同值
********************************************/
class Solution {
public:
    char findTheDifference(string s, string t) {
       char a = 0;
       for(auto i : t)
           a += i;
       for(auto j : s)
           a -= j;
        
       return a;
    }
};
