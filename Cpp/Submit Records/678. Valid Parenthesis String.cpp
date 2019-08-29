/********************************************
作者:Alfeim
题目:有效的括号字符串
时间消耗:4ms
解题思路:贪心算法
相似题目：
遍历字符串,用low high两个变量分别记录当前位置可能
有的最少和最多多左括号数(左括号=0意味着完全匹配、如果
小于0则无法匹配)

如果遇到'('就让low,high各+1
如果遇到')',让high-1,如果此时low > 0也将low-1
如果遇到'*',让high+1,同时如果此时low > 0也将low-1

遍历完后只需要看low是否为0即可

********************************************/

class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        int low = 0,high = 0;
        for(auto i : s){
            if(i == ')'){
                if(low > 0)low--;
                high--;
            }
            else if(i == '(')
                low++,high++;
            else{
                if(low > 0) low--;
                high++;
            }
            
            if(high < 0) return false;
        }
        return low == 0;
    }

};
