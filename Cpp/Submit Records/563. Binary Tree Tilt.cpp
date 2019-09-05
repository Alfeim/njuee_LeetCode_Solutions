/********************************************
作者:Alfeim
题目:二叉树的坡度
时间消耗:32ms
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
    int findTilt(TreeNode* root) {
        int res = 0;
        Solve(root,res);
        return res;
    }
    
    int Solve(TreeNode* root,int &res){
        if(!root) return 0;
        int left = Solve(root->left,res);
        int right = Solve(root->right,res);
        res += abs(left - right);
        return left + right + root->val;
        
    }  
};
