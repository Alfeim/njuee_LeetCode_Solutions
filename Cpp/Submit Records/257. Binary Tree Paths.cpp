/********************************************
作者:Alfeim
题目:二叉树的所有路径
时间消耗:4ms
解题思路:深度优先搜索
********************************************/
class Solution {
public:
    vector<string> res;
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root)
            return res;
        vector<int> tmp;
        tmp.push_back(root->val);
        dfs(root,tmp);
        return res;
    }
    
    void dfs(TreeNode* root,vector<int> &tmp){
        if(!root->left && !root->right){
            string ans;
            for(int i = 0 ; i < tmp.size();++i){
                ans += to_string(tmp[i]);   
                if(i < tmp.size() - 1) ans += "->";
            }
            res.push_back(ans);
        }
        
        if(root->left){
            tmp.push_back(root->left->val);
            dfs(root->left,tmp);
            tmp.pop_back();
        }
        
         if(root->right){
            tmp.push_back(root->right->val);
            dfs(root->right,tmp);
            tmp.pop_back();
        }

    }
};
