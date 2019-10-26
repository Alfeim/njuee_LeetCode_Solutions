/********************************************
作者:Alfeim
题目:反转每对括号间的子串
时间消耗:0ms
解题思路:递归
********************************************/
class Solution {
public:
    int n;
    string reverseParentheses(string s) {
       n = s.size();
       int pos = 0;
       return Solve(s,pos,false);
    }

    string Solve(string &s,int &pos,bool if_reverse){
        string res;
        while(pos < n){
            if(s[pos] == '('){
                pos++;
                string next = Solve(s,pos,true);
                res.append(next);
            }else if(s[pos] == ')'){
                break;
            }else{
                res.push_back(s[pos]);
            }
            pos++;
        }

        if(if_reverse) reverse(res.begin(),res.end());
        return res;
    }
};
