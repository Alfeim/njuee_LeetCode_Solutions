/********************************************
作者:Alfeim
题目:搜索旋转排序数组
时间消耗:8ms
解题思路:用递归最简单;题目进阶要求不用递归,则用辅助栈来模拟
之,注意，为了先遍历左节点，应当先压入右节点再压入左节点！
相似题目：145.二叉树的后序遍历
********************************************/
class Solution {
public:
    vector<int> res;
    stack<TreeNode*> S;
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root)
            return res;       
        S.push(root);
        while(!S.empty()){
            auto cur = S.top();
            res.push_back(cur->val);
            S.pop();
            if(cur->right)
                S.push(cur->right);
            if(cur->left)
                S.push(cur->left);
        }
        return res;  
    }
};
