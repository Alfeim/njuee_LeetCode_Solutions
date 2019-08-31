/********************************************
作者:Alfeim
题目:二叉搜索树的插入操作
时间消耗:120ms
解题思路:递归
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root){
            TreeNode* newroot = new TreeNode(val);
            return newroot;
        }
        
        Solve(root,val);
        return root;
    }
    
    void Solve(TreeNode* root,int &val){
        if(val < root->val){
            if(root->left){
                Solve(root->left,val);
            }else{
                TreeNode *cur = new TreeNode(val);
                root->left = cur;
            }
        }else{
            if(root->right){
                Solve(root->right,val);
            }else{
                TreeNode *cur = new TreeNode(val);
                root->right = cur;
            }
        }
 
        
    }
};
