/********************************************
作者:Alfeim
题目:回复二叉搜索树
时间消耗:36ms
解题思路:利用二叉搜索树中序遍历为递增序列的性质
********************************************/
class Solution {
public:
    TreeNode* first;
    TreeNode* second;
    TreeNode* prev;
    void recoverTree(TreeNode* root) {
        Solve(root);
        swap_node(first,second);
        return;
    }
    
    void Solve(TreeNode* root){
        if(!root)
            return;
        Solve(root->left);
        if( prev && prev->val > root->val) {
            if(!first)
                first = prev;
            second = root;
        }
        prev = root;
        Solve(root->right);
    }
    
    void swap_node(TreeNode *node1,TreeNode *node2){
        int tmp = node1->val;
        node1->val = node2->val;
        node2->val = tmp;
    }
    
};
