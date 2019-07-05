/********************************************
作者:Alfeim
题目:搜索旋转排序数组
时间消耗:12ms
解题思路:这一题和前序遍历的代码实际上没有太大出入，差异在于：前序
遍历顺序是 root->left->right 而后序遍历顺序是left->right->root
.但是，在迭代的过程中，总是会先便利到root，所以我们考虑按照root->
right->left的顺序存储结果，然后把结果翻转也就是我们需要的答案了。
相似题目：144.二叉树的前序遍历
********************************************/
class Solution {
public:
    stack<TreeNode*> S;
    vector<int> res;
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root)
            return res;
        
        S.push(root);
        while(!S.empty()){
            auto cur = S.top();
            res.push_back(cur->val);
            S.pop();
            if(cur->left)
                S.push(cur->left);
            if(cur->right)
                S.push(cur->right);
        } 
        reverse(res.begin(),res.end());
        return res;   
    }
};
