/********************************************
作者:Alfeim
题目:所有可能路径
时间消耗:196ms
解题思路:DFS
********************************************/
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> edges(n,vector<int>());
        vector<bool> visited(n,false);
        vector<int> tmp;
        
        for(int i = 0 ; i < n ; ++i){
            for(auto g : graph[i]) edges[i].push_back(g);    
        }
        
        visited[0] = true;
        tmp.push_back(0);
        Solve(0,n-1,tmp,visited,edges);
        return res;
        
    }
    
    void Solve(int src,int dst,vector<int>& tmp,vector<bool>& visited,vector<vector<int>> &edges){
        if(src == dst){
            res.push_back(tmp);
            return;
        }
        
        
        for(auto i : edges[src]){
            if(!visited[i]){
                visited[i] = true;   
                tmp.push_back(i);
                Solve(i,dst,tmp,visited,edges);
                tmp.pop_back();
                visited[i] = false;
            }
        }
        
        return;
    }
};
