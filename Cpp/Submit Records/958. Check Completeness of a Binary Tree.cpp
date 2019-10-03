/********************************************
作者:Alfeim
题目:二叉树的完全性检验
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
    queue<TreeNode*> Q;
    bool isCompleteTree(TreeNode* root) {
        if(!root) return true;
        
        bool IsEnd = false;
        int level = 0;
        Q.push(root);
        
        while(!Q.empty()){
            int size = Q.size();
            while(size--){
                auto cur = Q.front();
                Q.pop();
                
                if(cur->left){
                    if(IsEnd) return false;
                    Q.push(cur->left);    
                }else{
                    IsEnd = true;
                }
                
                if(cur->right){
                    if(IsEnd) return false;
                    Q.push(cur->right);
                }else{
                    IsEnd = true;
                }
            }
            
            level++;
            if(!IsEnd && Q.size() != pow(2,level)) return false;
  
        }
        
        return true;
        
    }
};
