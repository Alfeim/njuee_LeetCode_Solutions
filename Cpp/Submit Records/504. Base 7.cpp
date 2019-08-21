/********************************************
作者:Alfeim
题目:七进制数
时间消耗:0ms
解题思路:数学
********************************************/
class Solution {
public:
    string convertToBase7(int num) {
        int x = abs(num) , y = 0;
        bool flag = num >= 0 ? true : false;
        stack<char> S;
        string res;
        while(x >= 7){
            S.push('0' + x % 7);
            x /= 7;
        }
        S.push('0' + x);
        while(!S.empty()) res += S.top(),S.pop();
        return flag ? res : "-" + res;
        
    }
};
