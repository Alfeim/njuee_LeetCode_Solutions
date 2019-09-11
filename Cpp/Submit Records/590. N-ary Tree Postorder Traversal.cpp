/********************************************
作者:Alfeim
题目:N叉树的后序遍历
时间消耗:324ms
解题思路:栈
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
    vector<int> postorder(Node* root) {
        if(!root) return {};
        
        S.push(root); 
        stack<int>  tmpres;
        vector<int> res;
        
        while(!S.empty()){
            auto cur = S.top();
            S.pop();
            tmpres.push(cur->val);
            for(auto i : cur->children) if(i) S.push(i);
        }
        
        while(!tmpres.empty()){
            res.push_back(tmpres.top());
            tmpres.pop();
        }
        
        return res;

    }
};
