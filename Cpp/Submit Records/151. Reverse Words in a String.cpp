/********************************************
作者:Alfeim
题目:翻转字符串里的单词
时间消耗:8ms
解题思路:利用栈的性质即可
********************************************/
class Solution {
public:
    stack<string> S;
    string res;
    string reverseWords(string s) {
        for(int i = 0 ; i < s.size();){ 
            if(s[i] == ' '){
                ++i;
                continue;
            }
            
            string tmp;
            while(i < s.size() && s[i] != ' '){
                tmp += s[i++];
            }
            
            S.push(tmp);
        }
        while(!S.empty()){
            auto cur = S.top();
            S.pop();
            res += cur;
            if(!S.empty())
                res += ' ';
        } 
        return res;

    }
};
