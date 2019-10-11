/********************************************
作者:Alfeim
题目:图像渲染
时间消耗:32ms
解题思路:BFS
********************************************/
class Solution {
public:
    queue<pair<int,int>> Q;
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int rawColor = image[sr][sc];
        int m = image.size();
        int n = image[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        
        visited[sr][sc] = true;
        Q.push({sr,sc});
        
        while(!Q.empty()){
            int size = Q.size();
            while(size--){
                auto cur = Q.front();
                Q.pop();
                
                int i = cur.first;
                int j = cur.second;
                
                image[i][j] = newColor;
                
                if(i > 0 && image[i-1][j] == rawColor && !visited[i-1][j]) {
                    visited[i-1][j] = true;
                    Q.push({i-1,j});
                }
                if(i < m - 1 && image[i+1][j] == rawColor && !visited[i+1][j]) {
                    visited[i+1][j] = true;
                    Q.push({i+1,j});
                }
                if(j > 0 && image[i][j-1] == rawColor && !visited[i][j-1]){
                    visited[i][j-1] = true;
                    Q.push({i,j-1});
                } 
                if(j < n - 1 && image[i][j+1] == rawColor && !visited[i][j+1]){
                    visited[i][j+1] = true;
                    Q.push({i,j+1});
                } 
                
            }
        }
        
        return image;
        
    }
    
  
    
};
