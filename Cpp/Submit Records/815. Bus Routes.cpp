/********************************************
作者:Alfeim
题目:公交路线
时间消耗:184ms
解题思路:BFS
********************************************/
class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        unordered_map<int,unordered_set<int>> Graph; //graph[i]表示能够到达i站的所有公交车 
        unordered_set<int> visited1; //存储访问过的站点
        unordered_set<int> visited2; //存储访问过的公交车
        queue<int> Q;
        
        if(S == T) return 0;
        
        int n = routes.size();
        
        for(int i = 0 ; i < n ; ++i){
            for(auto j : routes[i]){
                Graph[j].insert(i);
            }
        }
        
   
        Q.push(S);
        visited1.insert(S);
        
        int step = 0;

        while(!Q.empty()){
            int size = Q.size();
            step++;
            
            while(size--){
                auto cur = Q.front();
                Q.pop();
                
                for(auto i : Graph[cur]){
                    if(!visited2.count(i)){
                        visited2.insert(i);
                        for(auto j : routes[i]){
                            if(j == T) return step;
                            if(!visited1.count(j)){
                                visited1.insert(j);    
                                Q.push(j);
                            }
                        }
                    }
                }
            }
        }
        
        return -1;
        
        
        
    }
};
