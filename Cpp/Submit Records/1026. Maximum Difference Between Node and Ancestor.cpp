/********************************************
作者:Alfeim
题目:节点与其祖先之间的最大差值
时间消耗:4ms/12ms
解题思路:dfs
********************************************/

//dfs思路1
class Solution {
public:
    vector<vector<int>> res;
    int maxAncestorDiff(TreeNode* root) {
        if(!root) return 0;
        
        
        vector<int> path;
        path.push_back(root->val);
        dfs(root,path);
        int ans = 0;
        
        int minval;
        int maxval;
        
        //遍历每条路径,每条路径的min和max之差也就是该路径的某个节点与祖先差的最大值
        for(auto i : res){
            minval = INT_MAX;
            maxval = INT_MIN;
            for(auto j : i){
                minval = min(minval,j);
                maxval = max(maxval,j);
            }
            
            ans = max(ans,maxval - minval);
        }
        
        
        return ans;
        
    }
    
    //所谓祖先与孩子,可以看作一条路径,我们只需要生成所有可能的路径也就拥有了所有的祖先关系
    void dfs(TreeNode* root,vector<int> &path){
        
        if(!root->left && !root->right){
            vector<int> tmp(path);
            res.push_back(tmp);
            return;
        }
        
        
        if(root->left){
            path.push_back(root->left->val);
            dfs(root->left,path);
            path.pop_back();
        }
        
        if(root->right){
            path.push_back(root->right->val);
            dfs(root->right,path);
            path.pop_back();
        }
        
        return;
    }
    
    
};




//dfs思路2
class Solution {
public:
    int res;
    int maxAncestorDiff(TreeNode* root) {
        res = 0;
        
        dfs(root,INT_MIN,INT_MAX);
        
        return res;
        
    }
    
    void dfs(TreeNode* root,int max,int min){
        if(!root) return;
        
        if(root->val > max) max = root->val;
        
        if(root->val < min) min = root->val;
        
        res = (max - min) > res ? max - min : res;
        
        dfs(root->left,max,min);
        dfs(root->right,max,min);
        
        return;
    }
    
    
};
