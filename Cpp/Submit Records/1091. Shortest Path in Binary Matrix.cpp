/********************************************
作者:Alfeim
题目:二进制矩阵中的最短路径
时间消耗:456ms
解题思路:BFS
********************************************/
class Solution {
public:
    int n;
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        n = grid.size();
        
        if(n == 0) return -1;
        if(n == 1) return 1;
        
        
        
        
        queue<pair<int,int>> Q;
        vector<vector<bool>> visited(n,vector<bool>(n,false));
        vector<vector<int>> pos{{0,-1},{0,1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
       
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
    
        //初始化
        Q.push({0,0});
        visited[0][0] = true;
        int step = 1,size = 0;
        
        while(!Q.empty()){
            size = Q.size();
            step++;
            while(size--){
                auto cur = Q.front();
                Q.pop();
                int newi = 0;
                int newj = 0;
                for(auto p : pos){
                    newi = cur.first + p[0];
                    newj = cur.second + p[1];
                    if(newi == n-1 && newj == n-1) return step;
                    if(isValidPos(newi,newj) && !visited[newi][newj] &&grid[newi][newj] == 0){
                        visited[newi][newj] = true;
                        Q.push({newi,newj});
                    }
                }
            }
        }
        
        return -1;
    }
    
    bool isValidPos(int i,int j){
        if(i >= 0 && i < n && j >= 0 && j < n) return true;
        return false;
    }
    
    
    
};
