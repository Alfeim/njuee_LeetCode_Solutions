/********************************************
作者:Alfeim
题目:最长特殊子序列
时间消耗:4ms
解题思路:没啥好说的..
相似题目:522. 最长特殊序列 II
********************************************/
class Solution {
public:
    int findLUSlength(string a, string b) {
        int m = a.size();
        int n = b.size();
        if(m > n) return m;
        if(n > m) return n;
        return a == b ? -1 : m;
    }
};
