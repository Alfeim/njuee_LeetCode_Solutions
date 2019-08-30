/********************************************
作者:Alfeim
题目:反转字符串2
时间消耗:4ms
解题思路:..没啥好说的
********************************************/
class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.size();
        for(int i = 0 ; i < n ; i += 2*k){
            int begin = i;
            int end = i + k - 1 > n - 1 ? n - 1 : i + k - 1;
            int len = end - begin + 1;
            reverse(s,begin,end);    
        }
        return s;
    }
    
    void reverse(string &s,int begin,int end){
        for(int i = begin , j = end ; i < j ; ++i,--j) swap(s[i],s[j]);
    }
};
