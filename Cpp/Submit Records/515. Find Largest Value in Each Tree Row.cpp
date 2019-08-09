/********************************************
作者:Alfeim
题目:在树的每一行寻找最大值
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
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        Q.push(root);
        while(!Q.empty()){
            int size = Q.size();
            int LevelMax = INT_MIN;
            while(size--){
                auto cur = Q.front();
                Q.pop();
                if(cur->left)  Q.push(cur->left);
                if(cur->right) Q.push(cur->right);
                LevelMax = max(cur->val,LevelMax);
            }
            res.push_back(LevelMax);
        }
        
        return res;
        
    }
};
