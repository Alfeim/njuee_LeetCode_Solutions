/********************************************
作者:Alfeim
题目:等式方程的可满足性
时间消耗:16ms
解题思路:图、BFS
********************************************/
class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        vector<vector<bool>> ban(26,vector<bool>(26,false));
        vector<vector<bool>> Graph(26,vector<bool>(26,false));
        vector<bool> hasEdge(26,false);
        
        for(auto i : equations){
            if(i[1] == '='){
                hasEdge[i[0] - 'a'] = true;
                hasEdge[i[3] - 'a'] = true;
                Graph[i[0] - 'a'][i[3] - 'a'] = true;
                Graph[i[3] - 'a'][i[0] - 'a'] = true;
            }else{
                if(i[0] == i[3]) return false;
                ban[i[0] - 'a'][i[3] - 'a'] = true;
                ban[i[3] - 'a'][i[0] - 'a'] = true;
            }
        }
        
        for(int i = 0 ; i < 25 ; i++){
            if(!hasEdge[i]) continue;
            int src = i;
            
            vector<bool> visited(26,false);
            queue<int> Q;
            visited[i] = true;
            Q.push(i);
            
            while(!Q.empty()){
                int size = Q.size();
                while(size--){
                    auto cur = Q.front();
                    Q.pop();
                    for(int i = 0 ; i < 25 ; ++i){
                        if(ban[cur][i] && Graph[src][i]) return false;
                        if(Graph[cur][i] && !visited[i]){
                            Q.push(i);
                            visited[i] = true;
                        }
                    }
                }
            }    
        }
        
        return true;
        
    }
    
    
};
