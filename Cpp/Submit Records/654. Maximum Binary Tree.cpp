/********************************************
作者:Alfeim
题目:最大二叉树
时间消耗:108ms
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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n = nums.size();
        return BuildMaxTree(nums,0,n-1);
    }
    
    TreeNode* BuildMaxTree(vector<int>& nums,int begin,int end){
        if(begin > end)
            return nullptr;
        
        int curval = INT_MIN;
        int curpos = begin;
        for(int i = begin ; i <= end ; ++i) if(nums[i] > curval){curval = nums[i],curpos = i;}
        TreeNode* cur = new TreeNode(curval);
        cur->left = BuildMaxTree(nums,begin,curpos-1);
        cur->right = BuildMaxTree(nums,curpos+1,end);
        
        return cur;
    }
    
    
};
