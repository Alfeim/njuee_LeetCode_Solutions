/********************************************
作者:Alfeim
题目:最小高度树
时间消耗:302ms
解题思路:BFS;和一般的BFS不同,我们并不是直接遍历所有
节点,而是先遍历“外围”节点,也就是那些只存在一个链接的
节点.将这些点入队;执行出队操作时,把对应的节点删除并
找到该节点链接的所有其他节点,让这些节点的度数减一,如果
减一后有存在度数为1的节点则入队;最终当队列里的节点数
少于2时,也就是所需要的答案
********************************************/
class Solution {
public:
    queue<int> Q;
    vector<int> res;
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if( n == 0 || edges.empty())
            return {0};
        
        unordered_map<int,unordered_set<int>> V;
        //保存每个节点对应的边
        for(auto i : edges){
            V[i[0]].insert(i[1]);
            V[i[1]].insert(i[0]);
        }
        
       for(auto j : V){
           if(j.second.size() == 1)
               Q.push(j.first);
        }
            
        while(n > 2){
            int size = Q.size();
            n -= size;
            while(size--){
                auto cur = Q.front();
                Q.pop();
                for(auto k : V[cur]){
                    V[k].erase(cur);
                    if(V[k].size() == 1)
                        Q.push(k);
                }
           }
        }
        
        while(!Q.empty()){
            res.push_back(Q.front());
            Q.pop();
        }
            
        return res;
    }
};
