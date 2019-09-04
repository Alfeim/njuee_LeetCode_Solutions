
/********************************************
作者:Alfeim
题目:冗余连接2
时间消耗:24ms
解题思路:分两种情况

1.存在入度为2的节点,那么就选择其两条边中的一条进行删除,并保证删除后没有环路
2.如果没有入度大于1的节点,思路与684.冗余连接1完全一致
********************************************/
class Solution {
public:
    struct DSU{
        int Len;
        vector<int> rank;
        vector<int> parent;
        DSU(int lenth):Len(lenth),rank(lenth + 1,0),parent(lenth + 1,0){
            for(int i = 0 ; i < lenth ; ++i){
                parent[i] = i;
            }
        };
        
        int find(int c){
            if(c == parent[c]) return c;
            parent[c] = find(parent[c]);
            return parent[c];
        }
        
        void Union(int x , int y){
            int _x = find(x);
            int _y = find(y);
            if(_x == _y) return;
            if(rank[_x] > rank[_y]) parent[_y] = _x;
            else if(rank[_x] < rank[_y]) parent[_x] = _y;
            else{
                parent[_y] = x;
                rank[_x] += 1;
            }
            return;
        }
    };
 
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> indegree(n,vector<int>());
        vector<int> res(2,0);
        DSU ele(n);
        bool flag = false;
        
        for(int i = 0 ; i < n ; ++i){
            if(!indegree[edges[i][1] - 1].empty() && !flag) flag = true;
            indegree[edges[i][1] - 1].push_back(i);
        }
        
        if(flag){
            for(int i = 0;i < n; ++i){
                if(indegree[i].size() > 1){
                    for(int j = indegree[i].size()-1; j >= 0; --j){
                        if(!checkRecyle(edges,indegree[i][j])){
                            return edges[indegree[i][j]];
                        }
                    }
                }
            }
        }
    
        
        ele.Union(edges[0][0],edges[0][1]);
        for(int i = 1 ; i < n ; ++i){
            int parent1 = ele.find(edges[i][0]);
            int parent2 = ele.find(edges[i][1]);
            if(parent1 == parent2){
                res[0] = edges[i][0];
                res[1] = edges[i][1];
            }else{
                ele.Union(edges[i][0],edges[i][1]);
            }
        }
        return res;
    }
    
    
    
    
     int find(vector<int> & f,int x){
            while(x != f[x]){
                x = f[x];
            }
            return x;
     }
  
     bool checkRecyle(vector<vector<int>> & edges, int edge_pos){
            int n = edges.size();
            vector<int> f(n+1,0);
            for(int i = 1;i <= n; ++i){
                f[i] = i;
            }
         
            for(int i = 0;i < n; ++i){
                if(i == edge_pos){
                    continue;
                }
                
                int _x1 = find(f,edges[i][0]);
                int _x2 = find(f,edges[i][1]);
                if( _x1 == _x2 ){
                    return true;
                }              
                    f[_x2] = _x1;
                
            }
        return false;
    }
    
    
    
    
    
};
