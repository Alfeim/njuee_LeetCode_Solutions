/********************************************
作者:Alfeim
题目:最长湍流子数组
时间消耗:88ms
解题思路:
DP
因为状态空间只与上一时刻有关 所以可以优化为两个变量记录
********************************************/
class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        int n = A.size(),res = 1;
        
        if(n == 0) return 0;
        
        int dp1 = 1 ,dp2 = 1;
        
        for(int i = 1 ; i < n ; ++i){
            if(i % 2 == 0){
                dp1 = ( A[i] < A[i-1] ) ? 1 + dp1 : 1;
            }else{
                dp1 = ( A[i] > A[i-1] ) ? 1 + dp1 : 1;
            }    
            res = max(dp1,res);
        }
        
        
        for(int i = 1 ; i < n ; ++i){
            if(i % 2 == 0){
                dp2 = ( A[i] > A[i-1] ) ? 1 + dp2 : 1;
            }else{
                dp2 = ( A[i] < A[i-1] ) ? 1 + dp2 : 1;
            }    
            res = max(dp2,res);
        }
        
        
        return res;
        
    }
};
