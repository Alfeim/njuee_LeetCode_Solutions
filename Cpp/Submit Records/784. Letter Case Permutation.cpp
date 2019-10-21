/********************************************
作者:Alfeim
题目:字母大小写全排列
时间消耗:16ms
解题思路:dfs
********************************************/
class Solution {
public:
    vector<string> res;
    int n ;
    
    vector<string> letterCasePermutation(string S) {
        n = S.size();
        dfs(0,S);
        return res;
    }

    void dfs(int pos,string &S){
        if(pos == n ){
            res.push_back(S);
            return;
        }
        
        if(!isdigit(S[pos])){
            S[pos] |= 32;
            dfs(pos+1,S);
            S[pos] &= -33;
            dfs(pos+1,S);
            return;
        }

        dfs(pos+1,S);
    }

};
