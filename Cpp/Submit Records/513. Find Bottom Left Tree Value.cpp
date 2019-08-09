/********************************************
作者:Alfeim
题目:找树左下角的值
时间消耗:12ms
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
    int findBottomLeftValue(TreeNode* root) {
        int res = 0;
        Q.push(root);
        while(!Q.empty()){
            int size = Q.size();
            int left = (Q.front())->val;
            while(size--){
                auto cur = Q.front();
                Q.pop();
                if(cur->left) Q.push(cur->left);
                if(cur->right) Q.push(cur->right);
            }
            if(Q.empty())
                res = left;
        }
        
        return res;
    }
};
