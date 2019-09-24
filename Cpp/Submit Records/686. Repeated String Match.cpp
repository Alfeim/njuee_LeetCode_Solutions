/********************************************
作者:Alfeim
题目:重复叠加字符串
时间消耗:12ms
解题思路:

不断叠加A,是否存在解取决于 当A的长度第一次超过B的长度 以及 A的长度第一次超过B的下一次时,A是否包含B
(因为当A的长度第一次超过B后,无论再怎么叠加A,如果当前已经包含B,之后也一定包含B)
********************************************/


class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        int res = 1;
        int m = A.size(),n = B.size();
        
        string cur(A);
        int tmp = cur.size();
        
        while(tmp < n){
            cur += A;
            tmp += m;
            res++;
        }
        
        if(cur.find(B) != string::npos){
            return res;
        }
        
        cur += A;
        res++;
        
        if(cur.find(B) != string::npos){
            return res;
        }
        
        return -1;
        
    }
};
