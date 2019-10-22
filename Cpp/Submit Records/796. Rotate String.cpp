/********************************************
作者:Alfeim
题目:旋转字符串
时间消耗:0ms
解题思路:利用周期性
********************************************/
class Solution {
public:
    bool rotateString(string A, string B) {
        if(A.size() != B.size()) return false;
        B.append(B);
        string::size_type res;
        res = B.find(A);
        return res != B.npos;
    }
};
