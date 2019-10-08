/********************************************
作者:Alfeim
题目:先序遍历构造二叉树
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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();
        return buildTree(preorder,0,n-1);
    }
    
    TreeNode* buildTree(vector<int>& preorder,int begin,int end){
        if(begin > end) return nullptr;
        
        int val = preorder[begin];
        TreeNode *cur = new TreeNode(val);
        
        int left_begin = begin + 1,right_begin = begin + 1;
        
        while(right_begin <= end){
            if( preorder[right_begin] > val ) break;
            right_begin++;
        }
        
        cur->left = buildTree(preorder,left_begin,right_begin - 1);
        cur->right = buildTree(preorder,right_begin,end);
        
        return cur;
    }
    
    
};
