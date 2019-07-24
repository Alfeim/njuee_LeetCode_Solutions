/********************************************
作者:Alfeim
题目:判断子序列
时间消耗:60ms
解题思路:贪心
********************************************/
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.size();
        int n = t.size();
        int i = 0;
        for(int j = 0 ; i < m && j < n ;++j){
            if(t[j] == s[i]) i++;
        }
        return i >= m ;
        
    }
};
