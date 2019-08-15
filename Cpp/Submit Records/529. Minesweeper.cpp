/********************************************
作者:Alfeim
题目:扫雷游戏
时间消耗:84ms
解题思路：bfs
********************************************/
class Solution {
public:
    queue<pair<int,int>> Q;
    vector<vector<int>> Pos;
    int m;
    int n;
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        if(board.empty())
            return board;
        
        Pos.push_back({-1,-1});
        Pos.push_back({-1,0});
        Pos.push_back({-1,1});
        Pos.push_back({0,1});
        Pos.push_back({0,-1});
        Pos.push_back({1,-1});
        Pos.push_back({1,0});
        Pos.push_back({1,1});
        m = board.size();
        n = board[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        bfs(visited,click,board);
        return board;
    }
    
    void bfs(vector<vector<bool>> &visited,vector<int> &click,vector<vector<char>> &board){
        int begin_row = click[0],begin_col = click[1];
        if(board[begin_row][begin_col] == 'M'){
              board[begin_row][begin_col] = 'X';
              return;
        }
        
        Q.push(make_pair(begin_row,begin_col));
        visited[begin_row][begin_col] = true;
        while(!Q.empty()){
            auto cur = Q.front();
            Q.pop();
            int i = cur.first;
            int j = cur.second;
            int bomb_count = 0;
            for(auto p : Pos){
                int newi = i + p[0];
                int newj = j + p[1];
                if(newi >= 0 && newi < m && newj >= 0 && newj < n && board[newi][newj] == 'M'){
                        bomb_count++;
                }
            }
            
            if(bomb_count > 0) 
                board[i][j] = '0' + bomb_count;
            else{ 
                board[i][j] = 'B';
                for(auto p : Pos){
                    int newi = i + p[0];
                    int newj = j + p[1];
                    if(newi >= 0 && newi < m && newj >= 0 && newj < n && !visited[newi][newj] && board[newi][newj] == 'E'){
                        visited[newi][newj] = true;
                        Q.push(make_pair(newi,newj));
                    }
                }
            }
            
            
            
            
        }
    }
    
    
    
};
