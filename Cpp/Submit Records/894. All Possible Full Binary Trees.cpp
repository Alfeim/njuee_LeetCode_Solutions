/********************************************
作者:Alfeim
题目:所有可能的满二叉树
时间消耗:12ms
解题思路:

显然 一颗满二叉树的所有子树也时满二叉树

所以我们要构造root为结点的满二叉树 只需要先构造其子
树为满二叉树(用列表存储所有可能情况下的子树结构)

可见子问题与原问题有相同的结构 自然运用递归

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
    vector<TreeNode*> allPossibleFBT(int N) {
        vector<TreeNode*> tmp;
        if( N % 2 == 0) return tmp;
        
        if( N == 1){
            TreeNode* cur = new TreeNode(0);
            tmp.push_back(cur);
            return tmp;
        }
        
        for(int i = 1 ; i <= N - 2 ; i += 2){
            vector<TreeNode*> left = allPossibleFBT(i);
            vector<TreeNode*> right = allPossibleFBT(N-1-i);            
            for(auto l : left){
                for(auto r : right){
                    TreeNode *cur = new TreeNode(0);
                    cur->left = l;
                    cur->right = r;
                    tmp.push_back(cur);
                }
            }
        }
        
        return tmp;
        
        
    }
    

    
};
