/********************************************
作者:Alfeim
题目:判断二分图
时间消耗:52ms
解题思路:BFS
********************************************/
class Solution {
public:
    queue<int> Q;
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> visited(n,0);
 
        for(int i = 0 ; i < n ; ++i){
            if(!graph[i].empty() && visited[i] == 0){        
                Q.push(i);
                visited[i] = 1;
                bool flag = false;
                while(!Q.empty()){
                    int size = Q.size();
                    while(size--){
                        auto i = Q.front();
                        Q.pop();
                        for(auto j : graph[i] ){
                            if(visited[j] == 0){
                                visited[j] = flag == true ? 1 : -1;                        
                                Q.push(j);
                            }else if( (flag == true && visited[j] == -1) || (flag == false && visited[j] == 1)) 
                                return false;  
                        }
                        
                    }    
                    flag = !flag;
               }              
            }   
       }    
        
       return true;
    }
};
