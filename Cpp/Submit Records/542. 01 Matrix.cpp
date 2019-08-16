/********************************************
作者:Alfeim
题目:01矩阵
时间消耗:12ms
解题思路:DP
类似于走迷宫那题,只不过不再是限定从左上往右下走，而是可以选择往左上或者右下走！
两种走法也就代表了状态空间的两种遍历方式,所以只需要遍历两次取最小的就行了
********************************************/
class Solution {
public:
    int m;
    int n;
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        m = matrix.size(),n = matrix[0].size();
        vector<vector<int>> dp(m,vector<int>(n,m + n));   
        for(int i = 0 ; i < m ; ++i){
            for(int j = 0 ; j < n ; ++j){
                if(matrix[i][j] == 0) 
                    dp[i][j] = 0;
                else{
                    dp[i][j] = min(i - 1 >= 0 ? dp[i-1][j] + 1 : m + n, j - 1 >= 0 ? dp[i][j-1] + 1 : m + n);
                }
            }
        }
        
        for(int i = m - 1 ; i >= 0 ; --i){
            for(int j = n - 1 ; j >= 0 ; --j){
                if(matrix[i][j] != 0){
                    int tmp = min(i + 1 < m ? dp[i+1][j] + 1 : m + n , j + 1 < n ? dp[i][j+1] + 1 : m + n );
                    dp[i][j] = min(tmp,dp[i][j]);
                }
            }
        }
        
        return dp;
    }

};
