/********************************************
作者:Alfeim
题目:从二叉搜索树到更大和树
时间消耗:4ms
解题思路:BFS
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
    TreeNode* bstToGst(TreeNode* root) {
        dfs(root,0);
        return root;
    }
    
    int dfs(TreeNode* root,int LastSum){
        
        if(!root) return 0;
        
        //tmp存储原节点的值
        int tmp = root->val;
        
        //sum1即右子树的和
        int sum1 = dfs(root->right,LastSum);
        //当前值加上右子树的和即是所有比当前值大的节点和
        root->val += sum1 + LastSum;
        //然后遍历左子树
        int sum2 = dfs(root->left,LastSum + tmp + sum1);
        
        return tmp + sum1 + sum2;
        
    }
};
