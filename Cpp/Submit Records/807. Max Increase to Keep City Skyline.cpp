/********************************************
作者:Alfeim
题目:保持城市天际线
时间消耗:8ms
解题思路:没啥好说的...
********************************************/
class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int m = grid.size(),n = grid[0].size(),res = 0;
        vector<int> rHeight(m,0);
        vector<int> cHeight(n,0);
        
        for(int row = 0 ; row < m ; ++row){
            int height = 0;
            for(int col = 0 ; col < n ; ++col){
                height = max(height,grid[row][col]);
            }
            rHeight[row] = height;
        }
        
        for(int col = 0 ; col < n ; ++col){
            int height = 0;
            for(int row = 0 ; row < m ; ++row){
                height = max(height,grid[row][col]);
            }
            cHeight[col] = height;
        }
        
        
        for(int i = 0 ; i < m ; ++i ){
            for(int j = 0 ; j < n ; ++j){
                res += min(rHeight[i],cHeight[j]) - grid[i][j];
            }
        }
        return res;
        
    }
};
