/********************************************
作者:Alfeim
题目:最长同值路径
时间消耗:184ms
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
    int res;
    int longestUnivaluePath(TreeNode* root) {
        res = 0; 
        Solve(root);
        return res;
    }
    

    int Solve(TreeNode* root){
        
        if(!root) return 0;
        
        int leftpath = Solve(root->left);
        int rightpath = Solve(root->right);
        
        int res1 = 0 , res2 = 0;
        if(root->left && root->left->val == root->val){
            res1 = 1 + leftpath;
        }
        
        if(root->right && root->right->val == root->val){
            res2 = 1 + rightpath;
        }
        
        res = max(res,res1 + res2);
        return max(res1,res2);
        
    }
    
    
};
