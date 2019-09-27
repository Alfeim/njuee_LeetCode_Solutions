/********************************************
作者:Alfeim
题目:打砖块
时间消耗:260ms
解题思路:

用倒序的思想

首先遍历一次hit,把对应位置的砖块-1;(有可能一个位置被hit很多次)

然后用一个set维护目前还剩下的砖块(只需要BFS第一行即可)

然后开始倒序遍历hit,每遍历到一个位置,先将对应标记+1,

如果该标记大于0,且其位于顶部、或者四周存在砖块位于record中(record即存储所有留存砖块的set)

则将其周围的砖块也一起恢复;而当前时刻掉落的砖块数即此次恢复前的砖块数目 - 恢复后的砖块数目 - 1(被hit的不算掉落)

********************************************/
class Solution {
public:
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        int n = hits.size();
        int m = grid[0].size();
        
        set<pair<int,int>> record;
        vector<int> res(n,0);
        
        for(auto i : hits){
            grid[i[0]][i[1]]--;
        }
        
        for(int i = 0 ; i < m ; ++i){
            if(grid[0][i] == 1) FindRemain(record,grid,0,i);
        }
        
        
        for(int i = n - 1 ; i >= 0 ; i--){
            int curi = hits[i][0],curj = hits[i][1];
            grid[curi][curj]++;
            if(grid[curi][curj] == 1){
                int last_size = record.size();
                if(curi == 0 || record.count({curi-1,curj}) || record.count({curi+1,curj}) || record.count({curi,curj+1}) || record.count({curi,curj-1})){
                    FindRemain(record,grid,curi,curj);   
                    res[i] = record.size() - last_size - 1;
                }
              
            }
        }
        
        return res;

    }
    
    
    
    void FindRemain(set<pair<int,int>>& record,vector<vector<int>>& grid,int i,int j){
  
        if(record.count({i,j})) return;
        
        int m = grid.size(),n = grid[0].size(); 
        
        record.insert({i,j});
        
        if(i + 1 < m  &&  grid[i+1][j] == 1) FindRemain(record,grid,i+1,j); 
        if(i - 1 >= 0 &&  grid[i-1][j] == 1) FindRemain(record,grid,i-1,j);
        if(j + 1 < n  &&  grid[i][j+1] == 1) FindRemain(record,grid,i,j+1);
        if(j - 1 >= 0 &&  grid[i][j-1] == 1) FindRemain(record,grid,i,j-1);
        
        return;
    }
};
    
    
    
    
    

    
    
    
    
