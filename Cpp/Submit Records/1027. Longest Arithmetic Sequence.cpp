/********************************************
作者:Alfeim
题目:最长等差数列
时间消耗:628ms
解题思路:DP
********************************************/
class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        
        int n = A.size();
        if(n == 0) return 0;
        
        int res = 1;
        
        //两个dp数组,分别存储正序列和反序列的结果
        vector<vector<int>> dp1(n,vector<int>(10001,1));
        vector<vector<int>> dp2(n,vector<int>(10001,1));
        
        //遍历正序列
        if(A[1] >= A[0]) {
            dp1[1][A[1] - A[0]] = 2;
            res = 2;
        }
        
        for(int i = 2 ; i < n ; ++i){
            for(int j = i - 1 ; j >= 0 ; --j){
                int diff = A[i] - A[j];
                if(diff < 0) continue;
                dp1[i][diff] = max(dp1[i][diff],1 + dp1[j][diff]);
                res = max(res,dp1[i][diff]);
            }
        }
        
        //遍历反序列
        vector<int> rA(A);
        reverse(rA.begin(),rA.end());
        
        if(rA[1] > rA[0]) {
            dp2[1][rA[1] - rA[0]] = 2;
            res = max(res,2);
        }
        
        for(int i = 2 ; i < n ; ++i){
            for(int j = i - 1 ; j >= 0 ; --j){
                int diff = rA[i] - rA[j];
                if(diff < 0) continue;
                dp2[i][diff] = max(dp2[i][diff],1 + dp2[j][diff]);
                res = max(res,dp2[i][diff]);
            }
        }
        
        return res;
        
        
    }
};
