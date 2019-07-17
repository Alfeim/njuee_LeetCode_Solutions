/********************************************
作者:Alfeim
题目:二维区域和检索-矩阵不可变
时间消耗:52ms
解题思路:动态规划,思路类似一维
相似题目:303. 区域和检索-数组不可变
********************************************/
class NumMatrix {
public:
    vector<vector<int>> dp;
    NumMatrix(vector<vector<int>>& matrix){
        if(!matrix.empty()){
            dp = vector<vector<int>>(matrix.size(),vector<int>(matrix[0].size(),0));
            dp[0][0] = matrix[0][0];  
     
            for(int i = 1 ; i < dp[0].size();++i){
              dp[0][i] = dp[0][i-1] + matrix[0][i];
            }
        
            for(int j = 1 ; j < dp.size();++j){
             dp[j][0] = dp[j-1][0] + matrix[j][0];
            }
        
            for(int k = 1; k < dp.size();++k){
              for(int l = 1 ; l < dp[0].size();++l){
                 dp[k][l] = dp[k][l-1] + dp[k-1][l] - dp[k-1][l-1] + matrix[k][l];
             }
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if(dp.empty())
            return 0;
        
        int Area = dp[row2][col2];
        int Part1 = col1 > 0 ? dp[row2][col1-1] : 0;
        int Part2 = row1 > 0 ? dp[row1-1][col2] : 0;
        int Part3 = row1 > 0 && col1 > 0 ? dp[row1-1][col1-1] : 0 ; 
        return Area - Part1 - Part2 + Part3;

    }
};
