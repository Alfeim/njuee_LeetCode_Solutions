/********************************************
作者:Alfeim
题目:克隆图
时间消耗:36ms
解题思路:广度优先搜索、哈希表
********************************************/
class Solution {
public:
    unordered_map<Node*,Node*> copy;  //copy用于存储原图的拷贝
    queue<Node*> Q;   //Q队列用于遍历原图
    Node* cloneGraph(Node* node) {
        if(!node)
            return nullptr;
        
        Q.push(node);
        copy[node] = new Node(node->val,vector<Node*>{});
        while(!Q.empty()){
            auto cur = Q.front();
            auto cpcur = copy[cur];            //取得当前节点的复制
            Q.pop();

            for( auto i : cur->neighbors){     //遍历其所有邻居
                if(copy.count(i) == 0){        //如果没有复制过，就新建并将原图的节点入队
                    copy[i] = new Node(i->val,vector<Node*>{});
                    Q.push(i);
                }
                //将这些邻居的复制填入拷贝节点的邻居中
                cpcur->neighbors.push_back(copy[i]);
            }
        }  
        return copy[node];
    }
};
