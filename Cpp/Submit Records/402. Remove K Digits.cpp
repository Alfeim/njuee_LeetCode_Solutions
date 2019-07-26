/********************************************
作者:Alfeim
题目:移掉K位数字
时间消耗:0ms
解题思路:贪心
********************************************/
class Solution {
public:
    string removeKdigits(string num, int k) {
        string S;
        int m = num.size();
        int left = m - k; 
        if(left <= 0)
            return "0";
        
        for(int i = 0 ; i < m ;++i){
            while(!S.empty() && num[i] < S.back() && S.size() + (m - i) > left )  S.pop_back();
            if(S.size() < left) S += num[i];
        }
        
        int i = 0;
        for(; i < S.size() && S[i] == '0';++i);
        string res(S.substr(i));
        return res.empty() ? "0" : res;
    }
};
