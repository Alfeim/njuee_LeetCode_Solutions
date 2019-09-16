/********************************************
作者:Alfeim
题目:二叉树的层平均值
时间消耗:28ms
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
    vector<double> averageOfLevels(TreeNode* root) {
        if(!root) return {};
        vector<double> res;
        int size = 0,tmpsize = 0;
        double tmp = 0.0;
        Q.push(root);
        while(!Q.empty()){
            size = Q.size();
            tmpsize = size;
            tmp = 0.0;
            while(size--){
                auto cur = Q.front();
                Q.pop();
                tmp += cur->val;
                if(cur->left) Q.push(cur->left);
                if(cur->right) Q.push(cur->right);
            }
            res.push_back(tmp/tmpsize);
        }
        
        return res;
    }
};
