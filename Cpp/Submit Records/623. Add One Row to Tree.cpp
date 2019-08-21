/********************************************
作者:Alfeim
题目:在二叉树种增加一行
时间消耗:32ms
解题思路:BFS层次遍历
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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if(!root) 
            return root;
        
        if(d == 1){
            TreeNode* NewRoot= new TreeNode(v);
            NewRoot->left = root;
            return NewRoot;
        }
        
        Q.push(root);
        int level = 1;
        while(!Q.empty() && level != d){
            int size = Q.size();
            while(size--){
                auto cur = Q.front();
                Q.pop();
                if(level != d - 1){
                    if(cur->left) Q.push(cur->left);
                    if(cur->right) Q.push(cur->right);
                }else{
                    TreeNode* newleft = new TreeNode(v);
                    if(cur->left) newleft->left = cur->left;
                    cur->left = newleft;
                    
                    TreeNode* newright = new TreeNode(v);
                    if(cur->right) newright->right = cur->right;
                    cur->right = newright;

                }

            }
              level++;
        }
        
        
        return root;
    }
};
