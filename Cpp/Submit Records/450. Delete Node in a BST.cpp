/********************************************
作者:Alfeim
题目:删除二叉搜索树中的节点
时间消耗:44ms
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
    TreeNode *dummy;
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)
            return root;
        
        dummy = new TreeNode(root->val + 1);
        dummy->left = root;
        Solve(dummy,key);
        return dummy->left;
    }
    
    void Solve(TreeNode* root,int key){
        if(!root)
            return;
        
        if(root->left && root->left->val == key){
            update(root,root->left,false);
            return;
        }
        if(root->right && root->right->val == key){
            update(root,root->right,true);
            return;
        }
        
        if(root == dummy)
            Solve(root->left,key);
        
        if(key < root->val)
            Solve(root->left,key);
        
        Solve(root->right,key);
    }
    
    
    void update(TreeNode *Father,TreeNode* toDelete,bool flag){
        
        if(!toDelete->left){
            if(flag) Father->right = toDelete->right;
            else Father->left = toDelete->right;
            return;
        }
        
        if(!toDelete->right){
            if(flag) Father->right = toDelete->left;
            else Father->left = toDelete->left;
            return;
        }
        
        TreeNode* child1 = toDelete->left;
        TreeNode* child2 = toDelete->right;
        if(flag) Father->right = child1;
        else Father->left = child1;
        insert(child1,child2);
        return;
        
    }
    
    
    void insert(TreeNode* root,TreeNode* toInsert){
       if(root->right){
           insert(root->right,toInsert);
           return;
       }
        root->right = toInsert;
        return;
    }
    
    
};
