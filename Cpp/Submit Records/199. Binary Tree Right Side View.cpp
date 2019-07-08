/********************************************
作者:Alfeim
题目:二叉树的右视图
时间消耗:8ms
解题思路:利用bfs进行层次遍历
********************************************/
class Solution {
public:
    queue<TreeNode*> Q;
    vector<int> res;
    vector<int> rightSideView(TreeNode* root) {
        if(!root)
            return res;  
        Q.push(root);
        int level = 0;
        while(!Q.empty()){
            int size = Q.size();
            level++;
            while(size--){
                auto cur = Q.front();
                Q.pop();
                
                if(res.size() < level)
                    res.push_back(cur->val);   
                if(cur->right)
                   Q.push(cur->right);
                if(cur->left)
                   Q.push(cur->left);
            }
            
        }
        return res;
    }
};
