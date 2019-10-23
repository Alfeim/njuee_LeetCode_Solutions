/********************************************
作者:Alfeim
题目:地图分析
时间消耗:44ms
解题思路:BFS
********************************************/
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n == 0) return 0;

        queue<pair<int,int>> Q;
        int landcount = 0;

        //先遍历一次，填入所有陆地，访问过即染色为“2”
        for(int i = 0 ; i < n ; ++i){
            for(int j = 0 ; j < n ; ++j){
                if(grid[i][j] == 1){
                    landcount++;
                    grid[i][j] = 2;
                    Q.push({i,j});
                }
            }
        }

        if(landcount == 0 || landcount == n*n) return -1;

        int distance = -1;
        int size = 0;
        int curi = 0;
        int curj = 0;

        while(!Q.empty()){
            distance++;
            size = Q.size();
            while(size--){
                auto cur = Q.front();
                Q.pop();
                curi = cur.first;
                curj = cur.second;
                if(curi + 1 < n && grid[curi+1][curj] == 0){ Q.push({curi+1,curj}); grid[curi+1][curj] = 2;}
                if(curj + 1 < n && grid[curi][curj+1] == 0){ Q.push({curi,curj+1}); grid[curi][curj+1] = 2;} 
                if(curi - 1 >= 0 && grid[curi-1][curj] == 0){ Q.push({curi-1,curj}); grid[curi-1][curj] = 2;}
                if(curj - 1 >= 0 && grid[curi][curj-1] == 0){ Q.push({curi,curj-1}); grid[curi][curj-1] = 2;}
            }
            
        }
        return distance;
    }
};
