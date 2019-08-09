/********************************************
作者:Alfeim
题目:出现次数最多的子树元素和
时间消耗:36ms
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
    unordered_map<int,int> record;
    vector<int> res;
    int maxcount;
    vector<int> findFrequentTreeSum(TreeNode* root) {
        maxcount = INT_MIN;
        dfs(root);
        return res; 
    }
    
    int dfs(TreeNode* root){
        if(!root)
            return 0;
        
        int sum1 = dfs(root->left);
        int sum2 = dfs(root->right);
        int sum = sum1 + sum2 + root->val;
        record[sum]++;
        
        if(record[sum] > maxcount){
            res.clear();
            res.push_back(sum);
            maxcount = record[sum];
        }else if(record[sum] == maxcount){
            res.push_back(sum);
        }

        return sum;
    }
    
    
};
