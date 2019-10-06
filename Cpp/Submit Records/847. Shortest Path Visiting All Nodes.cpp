/********************************************
作者:Alfeim
题目:访问所有节点的最短路径
时间消耗:320ms
解题思路:BFS 因为节点数目有限 所以可以用整型位来记录状态
********************************************/
class Solution {
public:
    int res;
    int N;
    int shortestPathLength(vector<vector<int>>& graph) {
        res = INT_MAX;
        N = graph.size();
        if(N <= 1) return 0;
        for(int i = 0 ; i < N ; ++i) bfs(i,graph);
        return res;
    }
    
    
    void bfs(int start,vector<vector<int>>& graph){
        queue<int> Q;
        unordered_set<int> visited;
        
        int flag = pow(2,N) - 1;
        //低N位表示哪些节点被访问到了(访问到了就置1)
        //高位表示当前的节点编号

        int number =  (start << N);
        visited.insert(number);
        
        number |= (1 << start);
        Q.push(number);
        
        int step = 0;
        
        while(!Q.empty()){
            int size = Q.size();
            step++;
            
            while(size--){
                auto cur = Q.front();
                Q.pop();
                int number = (cur >> N);
                
                //遍历可能的边
                for(auto i : graph[number]){
                    int curstat = (flag & cur);
                    int nextstat = curstat | (1 << i);
                    
                    if(visited.count(curstat | (i << N))) continue;                    
                    
                    if(nextstat == flag){
                        res = min(res,step);
                        return;
                    }
                    
                    visited.insert(curstat | (i << N)); 
                    
                    Q.push(nextstat | (i << N));
                }
                
            }
            
        }
        
        
        return;
        
    }
    
    
    
};
