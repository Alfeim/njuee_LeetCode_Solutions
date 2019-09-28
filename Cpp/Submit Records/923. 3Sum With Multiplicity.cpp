/********************************************
作者:Alfeim
题目:三数之和的多种可能
时间消耗:236ms
解题思路:DP
********************************************/
class Solution {
public:
    int threeSumMulti(vector<int>& A, int target) {
        int n = A.size();
        
        unordered_map<long,long> counts;
        vector<vector<long>> dp_2sum(n,vector<long>(301,0));
        vector<vector<long>> dp_3sum(n,vector<long>(301,0));
        
        //dp[i][j]表示到下标i为止 满足三元数之和等于j的数目
        //初始化第一个元祖(即A[0] + A[1] + A[2])
        counts[A[0]]++;
        counts[A[1]]++;
        dp_2sum[1][A[0] + A[1]] = 1;
        dp_3sum[2][A[0] + A[1] + A[2]] = 1; 
        
        long mod = 1000000007;
        
        //先计算两元祖个数
        for(int i = 2 ; i < n ; ++i){
            for(int j = 0 ; j <= target ; ++j){
                if(j < A[i]) 
                    dp_2sum[i][j] = (dp_2sum[i-1][j] + mod)%mod;   
                else{
                    dp_2sum[i][j] = (dp_2sum[i-1][j] + counts[j - A[i]] + mod)%mod;  
                }
            }
            counts[A[i]]++;
        }       
        
        

        
        //然后计算三元组个数
        for(int i = 3 ; i < n ; ++i){
            for(int j = 0 ; j <= target ; ++j){
                if(j < A[i]) 
                    dp_3sum[i][j] = (dp_3sum[i-1][j] + mod)%mod;
                else{
                    dp_3sum[i][j] = (dp_3sum[i-1][j] + dp_2sum[i-1][j-A[i]] + mod)%mod;
                }
            }
        }

        return dp_3sum[n-1][target];
        
    }
};
