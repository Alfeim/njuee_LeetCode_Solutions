/********************************************
作者:Alfeim
题目:冗余链接
时间消耗:8ms/56ms
解题思路:查找并集/dfs
********************************************/
//DSU(查找并集)方法
class Solution {
public:
    struct UnionFind{
        int Len;
        vector<int> parents;
        vector<int> rank;
        UnionFind(int Lenth):Len(Lenth),parents(Lenth+1,0),rank(Lenth+1,1){
            for(int i = 1 ; i <= Len ; ++i){
                parents[i] = i;
            }
        };
        
        int find(int x){
            if(x == parents[x]) return x;
            return find(parents[x]);
        }
        
        void merge(int x,int y){
            int _x = find(x);
            int _y = find(y);
            
            if(_x == _y) return;
            
            if(rank[_x] > rank[_y])
                parents[_y] = _x;
            else if(rank[_y] > rank[_x])
                parents[_x] = _y;
            else{
                parents[_y] = x;
                rank[_x] += 1;
            }
            
            return;
        }
        
    };
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> res(2,0);
        int n = edges.size();
        UnionFind DSU(n);
        DSU.merge(edges[0][0],edges[0][1]);

        for(int i = 1 ; i < n ; ++i){
            int first = DSU.find(edges[i][0]);
            int second = DSU.find(edges[i][1]);
            if(first > second) swap(first,second);
            if(first == second){
                res[0] = edges[i][0];
                res[1] = edges[i][1];
            }else{
                DSU.merge(edges[i][0],edges[i][1]);
            }
            
        }
        
        return res;
        
    }
  
};


//dfs方法
class Solution {
public:
    unordered_map<int,unordered_set<int>> V;
    map<pair<int,int>,int> pos_record;
    vector<int> NodeList;
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int pos = 0;
        for(auto i : edges){
            pos_record[make_pair(i[0],i[1])] = pos;
            pos_record[make_pair(i[1],i[0])] = pos;
            V[i[0]].insert(i[1]);
            V[i[1]].insert(i[0]);
            pos++;
        }
        
        int n = edges.size();
        vector<bool> visited(n+1,false); 
        NodeList.push_back(edges[0][0]);
        
        visited[edges[0][0]] = true;
        Solve(edges[0][0],n+1,NodeList,visited);
        
        
        int last = NodeList.back();
        int len = NodeList.size();
        int res_pos = 0;
        int tmpMax = 0;
        for(int i = len - 1; i > 0 ; --i){
            auto p = make_pair(NodeList[i],NodeList[i-1]);
            if(pos_record[p] > tmpMax){
                tmpMax = pos_record[p];
                res_pos = i;
            }
            
            if(NodeList[i-1] == last) break;
            
        }
        
        vector<int> res{NodeList[res_pos],NodeList[res_pos-1]};
        sort(res.begin(),res.end());
        return res;
        
    }
    
    bool Solve(int node,int last,vector<int>& NodeList,vector<bool> visited){

        for(auto i : V[node]){
            if(last == i) 
                continue;
            
            if(visited[i]){
                NodeList.push_back(i);
                return true;
            }
            
            visited[i] = true;
            NodeList.push_back(i);
            if(Solve(i,node,NodeList,visited)) return true;
            NodeList.pop_back();
            visited[i] = false;
        }
        
        return false;
        
    }
    
    
};
