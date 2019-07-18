/********************************************
作者:Alfeim
题目:去除重复字母
时间消耗:4ms
解题思路:每次入队时查看队尾元素的字典顺序是否高于
当前元素,如果更高,且在后续元素中还存在队尾元素,则出队,
重复此步骤直到队尾元素的字典顺序不高于当前元素或者
后续元素中不存在队尾元素;
为了知道后续元素中是否还有某个元素存在,通过计数器
的方式,先扫描一遍统计各个元素的个数,遍历到某个元素
就将其对应的计数器-1,如果发现某个元素的计数器>0说明后续
还存在该元素
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
