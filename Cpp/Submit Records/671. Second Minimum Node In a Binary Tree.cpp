/********************************************
作者:Alfeim
题目:二叉树中第二小的节点
时间消耗:4ms
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
    int findSecondMinimumValue(TreeNode* root) {
        if(!root) return -1;
        return Solve(root,root->val);
        
    }
    
    int Solve(TreeNode* root,int target){
        if(root->val > target) 
            return root->val;
        
        if(!root->left) 
            return -1;
        
        int val1 = Solve(root->left,target);
        int val2 = Solve(root->right,target);
        
        if(val1 == -1 && val2 == -1) return -1;
        else if(val1 == -1) return val2;
        else if(val2 == -1) return val1;
        
        return min(val1,val2);
    }
};
