/********************************************
作者:Alfeim
题目:扰乱字符串
时间消耗:8ms
解题思路:递归
********************************************/
class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1.size() != s2.size())
            return false;    
        if(s1 == s2)
            return true;     
        string tmps1(s1);
        string tmps2(s2);
        sort(tmps1.begin(),tmps1.end());
        sort(tmps2.begin(),tmps2.end());
        
        if(tmps1 != tmps2)
            return false;
        
        for(int i = 1 ; i < s1.size();++i){
            if(isScramble(s1.substr(0,i),s2.substr(0,i))  && isScramble(s1.substr(i),s2.substr(i)))
                return true;
            if(isScramble(s1.substr(0,i),s2.substr(s2.size()-i)) && isScramble(s1.substr(i),s2.substr(0,s2.size()-i)))
                return true;
        }
        
        return false;
    }
};
