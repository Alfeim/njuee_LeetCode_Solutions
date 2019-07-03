/********************************************
作者:Alfeim
题目:不同的二叉搜索树2
时间消耗:8ms
解题思路:递归
相似题目：No.96 不同的二叉搜索树
********************************************/
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
       if(n == 0)
           return {};
        return Solve(1,n);
    }
    
    vector<TreeNode*> Solve(int begin,int end){
        vector<TreeNode*> V;
        
        if(begin > end)
            V.push_back(nullptr);
          
        for(int i = begin ; i <= end ; ++i){ 
            vector<TreeNode*> left = Solve(begin,i-1);
            vector<TreeNode*> right = Solve(i+1,end);   
            for(auto j : left){
                for(auto k : right){
                    TreeNode *root = new TreeNode(i);
                    root->left = j;
                    root->right = k;
                    V.push_back(root);
                }
            }
        }
        
        return V;
    }
    
};
