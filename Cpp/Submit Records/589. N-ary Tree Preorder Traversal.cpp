/********************************************
作者:Alfeim
题目:N叉树的前序遍历(非递归)
时间消耗:268ms
解题思路:DFS
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
    stack<Node*> S;
    vector<int> preorder(Node* root) {
        if(!root) return {};
        vector<int> res;
        S.push(root);
        
        while(!S.empty()){
            auto cur = S.top();
            S.pop();
            res.push_back(cur->val);
            int n = (cur->children).size();
            for(int i = n - 1;  i >= 0 ; i--){
                if(cur->children[i]) S.push(cur->children[i]);
            }
        }
        
        return res; 
    }
};
