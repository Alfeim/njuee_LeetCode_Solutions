/********************************************
作者:Alfeim
题目:N叉树的层次遍历
时间消耗:20ms
解题思路:BFS
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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if(!root) return res;
        
        queue<Node*> Q;
        Q.push(root);
        int size = 1;
        
        while(!Q.empty()){
            int tmp = 0;
            vector<int> level;
            while(size--){
                auto cur = Q.front();
                level.push_back(cur->val);
                Q.pop();
                tmp  += cur->children.size();
                for(auto i : cur->children) 
                    Q.push(i);
            }
            res.push_back(level);
            size = tmp;
        }
        
        return res;
    }
};
