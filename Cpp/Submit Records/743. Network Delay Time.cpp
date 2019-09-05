/********************************************
作者:Alfeim
题目:网络延迟时间
时间消耗:220ms
解题思路:Dijkstra最短路径算法
********************************************/
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        //用一个二维map存储edges
        //edges[i]即表示节点i的所有边与权值
        unordered_map<int,map<int,int>> edges;
        for(auto i : times) edges[i[0]][i[1]] = i[2];  
        //Dijkstra算法,维护一个候选列表,初始化为K的所有边
        map<int,int> Candidates(edges[K]);
        //遍历候选列表,每次取出候选列表的首位,直到列表为空
        while(!Candidates.empty()){
            int curNode = (Candidates.begin())->first;
            for(auto i : edges[curNode]){
                if(edges[K].count(i.first) == 0 || edges[K][curNode] + i.second < edges[K][i.first] ){
                        edges[K][i.first] = edges[K][curNode] + i.second;    
                        Candidates[i.first] = edges[K][i.first];
                }
            }
            Candidates.erase(curNode);
        }
        
        int res = 0;
        for(int i = 1 ; i <= N ; ++i){
            if(i == K ) continue;
            if(edges[K].count(i) == 0) return -1;    
            res = max(res,edges[K][i]);
        }
        
        return res;
        
    }
};
