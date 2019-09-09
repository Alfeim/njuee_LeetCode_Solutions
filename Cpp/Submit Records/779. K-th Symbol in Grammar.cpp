/********************************************
作者:Alfeim
题目:第K个语法符号
时间消耗:12ms
解题思路:递归
我们很容易看出,下一行的字符等于本行的字符 + 本行字符取反
********************************************/
class Solution {
public:
    int kthGrammar(int N, int K) {
        return Solve(N,K);
    }
    
    int Solve(int N,int K){
        if(N == 1) return 0;
        int bits = pow(2,N-1);
        if(K <= bits/2) return Solve(N-1,K);  
        return 1^(Solve(N-1,K - bits/2));
    }
};
