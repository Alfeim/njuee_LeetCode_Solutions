/********************************************
作者:Alfeim
题目:字符串的最短距离
时间消耗:16ms
解题思路:正序、反序遍历一次即可
********************************************/
class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        int n = S.size();
        vector<int> res(n,10001);
        int lastpos = -1;

        for(int i = 0 ; i < n ; ++i){
            if(S[i] == C) lastpos = i;
            res[i] = (lastpos == -1)? res[i] : i - lastpos;
        }

        lastpos = -1;

        for(int i = n-1 ; i >= 0 ; --i){
            if(S[i] == C) lastpos = i;
            res[i] = (lastpos == -1) ? res[i] : min(lastpos - i,res[i]);
        }

        return res;
         
    }
};
