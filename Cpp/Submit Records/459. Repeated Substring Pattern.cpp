/********************************************
作者:Alfeim
题目:重复的子字符串
时间消耗:44ms
解题思路:没啥好解释。。
********************************************/
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        for(int i = 0 ; i < n / 2; ++i){
            if(n % (i + 1) == 0  &&  isRepeated(s,s.substr(0,i+1)))
                return true;
        }
        
        return false;
        
    }
    
    bool isRepeated(string s,string pattern){
        int m = s.size();
        int n = pattern.size();
        for(int i = 0 ; i < m ; i = i + n){
            if(s.substr(i,n) != pattern) return false;
        }
        
        return true;
        
    }
};
