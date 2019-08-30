/********************************************
作者:Alfeim
题目:岛屿的最大面积
时间消耗:64ms
解题思路:dfs
********************************************/
class Solution {
public:
    int res;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<int>> pos{{0,1},{1,0},{0,-1},{-1,0}};
        res = 0;
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0 ; i < m ; ++i){
            for(int j = 0 ; j < n ; ++j){
                if(grid[i][j] == 1){
                    grid[i][j] = 2;
                    res = max(dfs(i,j,grid,m,n,pos),res);
                }   
            }
        }
        
        return res;
    }
    
     int dfs(int i,int j,vector<vector<int>>& grid,int &m,int &n, vector<vector<int>> &pos){
         int sum = 1 ;
 
         for(auto p : pos){
             int newi = i + p[0];
             int newj = j + p[1];
             if(newi >= 0 && newi < m && newj >= 0 && newj < n && grid[newi][newj] == 1){
                grid[newi][newj] = 2;
                sum += dfs(newi,newj,grid,m,n,pos);
             }
         }

         return sum;
    }
    
   
};
