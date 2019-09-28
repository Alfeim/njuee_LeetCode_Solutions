/********************************************
作者:Alfeim
题目:环形子数组的最大和
时间消耗:80ms
解题思路:DP
分两种情况
1.只有一个数组
2.包含前后两个数组
********************************************/
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int n = A.size();
        
        int res1 = A[0];
        int res2 = A[0];
        int tmp = 0;
        
        //先计算单数组情况
        for(auto i : A){
            tmp = i + max(tmp,0);
            res1 = max(tmp,res1);
        }
        
        //然后计算双数组情况
        
        vector<int> sumright(n,0);
        vector<int> maxright(n,0);
        sumright[n-1] = A[n-1];
        maxright[n-1] = A[n-1];
        
        for(int i = n - 2 ; i >= 0 ; --i) sumright[i] = A[i] + sumright[i+1];
        for(int i = n - 2 ; i >= 0 ; --i) maxright[i] = max(sumright[i],maxright[i+1]);
        
        
        int leftsum = 0;
        for(int i = 0 ; i < n - 2 ; ++i){
            leftsum += A[i];
            res2 = max(res2,leftsum + maxright[i+2]);
        }
        
        return max(res1,res2);
    
        
    }
};
