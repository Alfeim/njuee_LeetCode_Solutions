/********************************************
作者:Alfeim
题目:二叉搜索树结点的最小距离
时间消耗:4ms
解题思路:中序遍历
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
    TreeNode* last;
    int res;
    int minDiffInBST(TreeNode* root) {
        res = -1;
        last = nullptr;
        Solve(root);
        return res == -1 ? 0 : res;
    }
    
    void Solve(TreeNode* root){
        if(!root) return;
        
        Solve(root->left);
        
        if(last != nullptr){
            int diff = root->val - last->val;
            if(res == -1 || diff < res) res = diff;
        }
        
        last = root;
        Solve(root->right);
        
    }
};
