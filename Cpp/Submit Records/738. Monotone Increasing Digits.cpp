
/********************************************
作者:Alfeim
题目:单调递增的数字
时间消耗:0ms
解题思路:从高位开始遍历,遇到非递增序列就反推到与当前
的数值相等的位置,然后将该位置的值-1并将后序的值全部置9
********************************************/
class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        string tmp(to_string(N));
        int n = tmp.size();   
        string res;
        for(int i = 0 ; i < n ; ++i){
            res += tmp[i];
            if(i < n - 1){
                if(tmp[i] > tmp[i+1]){
                    int pos = i;
                    while(pos > 0 && tmp[pos] == tmp[pos-1]) pos--;
                    res[pos] -= 1;
                    res = res.substr(0,pos+1) + string(n-1-pos,'9');
                    return stoi(res);
                }
            }
        }
        
        return stoi(res);
    }
};
