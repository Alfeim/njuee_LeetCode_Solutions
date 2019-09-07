/********************************************
作者:Alfeim
题目:另一个树的子树
时间消耗:36ms
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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(SameTree(s,t)) return true;
        
        if(s){
           if(isSubtree(s->left,t)) return true;
           if(isSubtree(s->right,t)) return true;
        } 
        
        return false;
        
    }
    
    bool SameTree(TreeNode* root,TreeNode* target){
        if(!root && !target) return true;
       
        if(root && !target || !root && target || root->val != target->val ) return false;
        
        return SameTree(root->left,target->left) && SameTree(root->right,target->right);
        
    }
    
};
