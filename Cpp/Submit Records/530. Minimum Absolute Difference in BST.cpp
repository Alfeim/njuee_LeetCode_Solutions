/********************************************
作者:Alfeim
题目:二叉搜索树的最小绝对差
时间消耗:24ms
解题思路:利用二叉搜索树的中序遍历是升序的性质
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
    int getMinimumDifference(TreeNode* root) {
        res = INT_MAX;
        Solve(root,nullptr);
        return res;
    }
    
    TreeNode* Solve(TreeNode* cur,TreeNode *prev){
        if(cur->left){
            TreeNode* tmp = Solve(cur->left,prev);
            res = min(res,cur->val - tmp->val);
        }else if(prev)
            res = min(res,cur->val - prev->val);
        
        if(cur->right) 
            return Solve(cur->right,cur);
        
        return cur;
    }
 
};
