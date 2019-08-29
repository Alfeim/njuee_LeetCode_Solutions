/********************************************
作者:Alfeim
题目:冗余链接
时间消耗:56ms
解题思路:查找并集/dfs
********************************************/

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
