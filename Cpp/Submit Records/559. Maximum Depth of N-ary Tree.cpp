/********************************************
作者:Alfeim
题目:N叉树的最大深度
时间消耗:284ms
解题思路:BFS层次遍历
********************************************/
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    queue<Node*> Q;
    int maxDepth(Node* root) {
        if(!root) return 0;
        Q.push(root);
        int res = 0;
        while(!Q.empty()){
            res++;
            int size = Q.size();
            while(size--){
                auto cur = Q.front();
                Q.pop();
                for(auto i : cur->children) if(i) Q.push(i);  
            }
        }
        return res;
    }
};
