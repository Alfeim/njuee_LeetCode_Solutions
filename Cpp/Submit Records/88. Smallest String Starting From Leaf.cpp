/********************************************
作者:Alfeim
题目:从叶节点开始的最小字符串
时间消耗:16ms
解题思路:DFS、自动排序
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
    struct cmp{
        bool operator()(const string& str1,const string &str2) const{
            int m = str1.size(),n = str2.size();
            int i = 0;
            
            for(; i < m && i < n ; ++i){
                if(str1[i] < str2[i]) return true;
                else if(str1[i] > str2[i]) return false;
            }
            
            return  i < n ;
        }    
    };
    
    vector<string> res;
    string smallestFromLeaf(TreeNode* root) {
        if(!root) return "";
        
        dfs("",root);
        sort(res.begin(),res.end(),cmp());
        return res[0];
    }
    
    void dfs(string cur,TreeNode* root){
        char word = ('a' + root->val);
        string next = string(1,word) + cur;
        
        if(!root->left && !root->right) {
            res.push_back(next);
            return;
        }
        
        if(root->left) dfs(next, root->left);
        if(root->right) dfs(next, root->right);
    }
    
    
};
