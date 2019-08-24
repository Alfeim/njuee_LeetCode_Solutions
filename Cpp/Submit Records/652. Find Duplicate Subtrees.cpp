/********************************************
作者:Alfeim
题目:寻找重复的子树
时间消耗:48ms
解题思路:哈希表、dfs
********************************************/
class Solution {
public:
    unordered_map<string,int> record;
    vector<TreeNode*> ans;
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        dfs(root);
        return ans;
    }
    
     string dfs(TreeNode* root){
         if(!root) 
             return "*";
         string res = to_string(root->val);
         res += dfs(root->left);
         res += dfs(root->right);
         
         record[res]++;
         if(record[res] == 2){
             ans.push_back(root);
         } 
         
         return res;
     }
};
