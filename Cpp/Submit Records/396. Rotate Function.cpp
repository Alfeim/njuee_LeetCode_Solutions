/********************************************
作者:Alfeim
题目:旋转函数
时间消耗:20ms
解题思路:阶梯算法
********************************************/
class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        long sum = 0;
        long res = 0;
        int n = A.size();

        for(int i = 0 ; i < n ; ++i){
            sum += A[i];
            res += A[i] * i;
        }
        
        long tmpSum = res;
        for(int k = 1 ; k < n ; ++k){
            long last = A[n-k];
            long add = sum - last;
            long minus = (n-1) * last;
            tmpSum += add - minus;
            res = max(res,tmpSum);
            
        }
        
        return res;
        
    }
};
