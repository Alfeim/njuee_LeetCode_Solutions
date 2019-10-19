/********************************************
作者:Alfeim
题目:颜色交替的最短路径
时间消耗:36ms
解题思路:BFS
********************************************/
class Solution {
public:
    unordered_map<int,unordered_set<int>> blueEdge;
    unordered_map<int,unordered_set<int>> redEdge;
    
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        
        //先初始化所有节点对应的蓝色边和红色边
        
        for(auto i : red_edges){
            redEdge[i[0]].insert(i[1]);
        }
        
        for(auto i : blue_edges){
            blueEdge[i[0]].insert(i[1]);
        }
        
        //res存储结果
        vector<int> res(n,-1);
        res[0] = 0;
        
        //按照先遍历蓝色 和 先遍历红色 两种情况各执行一次bfs即可
        Solve(res,0);
        Solve(res,1);
 
        return res;
    }
    
    
    void Solve(vector<int> &res,int first_flag){   
        //first_flag为1表示首先遍历蓝色边，否则表示首先遍历红色边
        
        int n = res.size();
        queue<int> Q;
        vector<bool> visited_blue(n,false);
        vector<bool> visited_red(n,false);
        
        Q.push(0);
        
        visited_red[0] = true;
        visited_blue[0] = true;
        
        int step = 0;
        int size = 0;
        
        while(!Q.empty()){
            step++;
            size = Q.size();
            while(size--){
                auto cur = Q.front();
                Q.pop();
                if(step % 2 == first_flag){
                    for(auto i : blueEdge[cur]){
                        if(!visited_blue[i]){
                            visited_blue[i] = true;
                            Q.push(i);
                            if(res[i] == -1 || res[i] > step) res[i] = step;
                        }
                    }
                }else{
                    for(auto i : redEdge[cur]){
                        if(!visited_red[i]){
                            visited_red[i] = true;
                            Q.push(i);
                            if(res[i] == -1 || res[i] > step) res[i] = step;
                        }   
                    }
                }
            }
        }
    }
    
    
    
    
    
};
