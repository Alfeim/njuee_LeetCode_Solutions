
/********************************************
作者:Alfeim
题目:为高尔夫比赛砍树
时间消耗:超时(待优化)
解题思路:BFS
********************************************/
class Solution {
public:
    int cutOffTree(vector<vector<int>>& forest) {
        int pos[4][2]{{1,0},{0,1},{-1,0},{0,-1}};
        int res = 0;
        set<int> Trees;
        int m = forest.size(),n = forest[0].size();
        for(int i = 0 ; i < m ; ++i){
            for(int j = 0 ; j < n ; ++j){
                if(forest[i][j] > 1) Trees.insert(forest[i][j]); 
            }
        }
        
        int src_i = 0,src_j = 0,dst_high = 0,tmp = 0;     
        for(auto p : Trees){
            dst_high = p;
            tmp  = bfs(forest,src_i,src_j,dst_high,pos);
            if(tmp == -1) return -1;
            res += tmp;
        }
    
        return res;
    }
    
    int bfs(vector<vector<int>>& forest,int &src_i,int &src_j,int dst_high,int(&pos)[4][2]){
        if(forest[src_i][src_j] == dst_high) return 0;
        int m = forest.size(),n = forest[0].size(),level = 0;  
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        visited[src_i][src_j] = true;
        queue<pair<int,int>> Q;
        Q.push(make_pair(src_i,src_j));
        
        while(!Q.empty()){
            level++;
            int size = Q.size();
            while(size--){
                auto cur = Q.front();
                Q.pop();
                int tmp_i = cur.first;
                int tmp_j = cur.second;
                for(int i = 0 ; i < 4 ; ++i){
                    int newi = tmp_i + pos[i][0];
                    int newj = tmp_j + pos[i][1];
                    if(newi >= 0 && newj >=0 && newi < m && newj < n){
                        if(forest[newi][newj] == dst_high){
                            src_i = newi;
                            src_j = newj;
                            return level;
                        }
                        if(!visited[newi][newj] && forest[newi][newj] > 0){
                            visited[newi][newj] = true;
                            Q.push(make_pair(newi,newj));   
                        }    
                    }
                }
            }  
        }
        
        return -1;
    }

};
