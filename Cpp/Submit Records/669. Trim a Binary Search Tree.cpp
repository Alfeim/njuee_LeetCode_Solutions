/********************************************
作者:Alfeim
题目:修剪二叉搜索树
时间消耗:12ms
解题思路:二叉树中序遍历
********************************************/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if(!root) return nullptr;
        
        root->left = trimBST(root->left,L,R);
        
        if(root->val < L) 
            return trimBST(root->right,L,R);
        
        if(root->val > R){
            return root->left;
        }
        
        root->right = trimBST(root->right,L,R);
        
        return root;
    }
};
