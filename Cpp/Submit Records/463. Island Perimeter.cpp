/********************************************
作者:Alfeim
题目:岛屿周长
时间消耗:92ms
解题思路:
数学:依次遍历每个格子,遇到为1就让res+4,如果其之前
相邻的格子也为1,就让res - 2(因为相当于抵消了两条
边)

或者 BFS
********************************************/
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid){
        int res = 0;
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0 ; i < m ; ++i){
            for(int j = 0 ; j < n ; ++j){
                if(grid[i][j] == 1){
                    res += 4;
                    if(i > 0 && grid[i-1][j] == 1)
                        res -= 2;
                    if(j > 0 && grid[i][j-1] == 1)
                        res -=2;
                }
            }
        }
        return res; 
    }
    /*bfs
    queue<pair<int,int>> Q;
    vector<vector<int>> pos;
    int res;
    int islandPerimeter(vector<vector<int>>& grid) {
        res = 0;
        pos.push_back({1,0});
        pos.push_back({-1,0});
        pos.push_back({0,1});
        pos.push_back({0,-1});
        int m = grid.size(),n = grid[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        
        for(int i = 0 ; i < m ; ++i){
            for(int j = 0 ; j < n ; ++j){
                if(grid[i][j] == 1){
                    Solve(i,j,m,n,grid,visited);
                    return res;
                }
            }
        }
        
        return 0;
        
    }
    
    
    void Solve(int y , int x, int m , int n,vector<vector<int>>& grid,vector<vector<bool>>& visited){
        Q.push(make_pair(y,x));
        visited[y][x] = true;
        while(!Q.empty()){
            auto cur = Q.front();
            Q.pop();
            int i = cur.first;
            int j = cur.second;
            res += 4;
            for(auto p : pos){
                int newi = i + p[0];
                int newj = j + p[1];
                if( newi >= 0 && newi < m && newj >= 0 && newj < n){
                    if(grid[newi][newj] == 1){
                        res--;
                        if(!visited[newi][newj]){
                            visited[newi][newj] = true;
                            Q.push(make_pair(newi,newj));   
                        }
                    }
                }    
            }
        }  
    }
    */
};
