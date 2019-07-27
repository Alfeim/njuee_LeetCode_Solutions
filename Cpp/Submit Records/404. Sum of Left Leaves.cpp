/********************************************
作者:Alfeim
题目:左叶子之和
时间消耗:0ms
解题思路:递归
********************************************/
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        return Solve(root,false);  
    }
    
    int Solve(TreeNode* root,bool flag){
        if(!root)
            return 0;
        
        if(flag && !root->left && !root->right)
            return root->val;
        
        return Solve(root->left,true) + Solve(root->right,false);
        
    }
    
};
