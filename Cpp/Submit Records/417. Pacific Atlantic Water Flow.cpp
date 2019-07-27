/********************************************
作者:Alfeim
题目:太平洋大西洋水流问题
时间消耗:104ms
解题思路:要满足题意,实际上只要满足节点能够到四个边界
即可.所以可以从四个边界开始进行四次dfs,最终分别得到
可以流向太平洋和流向大西洋的节点。取两个集合的交集
即可
********************************************/
class Solution {
public:
    vector<vector<int>> pos;
    vector<vector<int>> res;
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if( m == 0)
            return res;
        int n = matrix[0].size();
        pos.push_back({1,0});
        pos.push_back({-1,0});
        pos.push_back({0,1});
        pos.push_back({0,-1});
  
        vector<vector<bool>> TPY(m,vector<bool>(n,false));
        vector<vector<bool>> DXY(m,vector<bool>(n,false));
        for(int i = 0 ; i < m ; ++i){
            dfs(i,0,matrix,TPY,matrix[i][0]);
            dfs(i,n-1,matrix,DXY,matrix[i][n-1]);
        }
        
        for(int j = 0 ; j < n; ++j){
            dfs(0,j,matrix,TPY,matrix[0][j]);
            dfs(m-1,j,matrix,DXY,matrix[m-1][j]);
        }
        
        
        for(int k = 0 ; k < m ;++k){
            for(int l = 0 ; l < n; ++l){
                if(TPY[k][l] && DXY[k][l])
                    res.push_back({k,l});
            }
        }
        
        return res;
        
        
        
    }
    
    void dfs(int i,int j,vector<vector<int>> &matrix, vector<vector<bool>> &visited,int last){ 
        if(!isValid(i,j,matrix) || visited[i][j] || last > matrix[i][j])
            return;
        
        visited[i][j] = true;
        for(auto k : pos)
            dfs(i + k[0],j + k[1],matrix,visited,matrix[i][j]);
    }
    
    
    bool isValid(int i , int j , vector<vector<int>> &matrix){
        if(i < 0 || j < 0 || i >= matrix.size() || j >= matrix[0].size())
            return false;      
        return true;
    }
    
    
};
