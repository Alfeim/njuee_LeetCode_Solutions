/********************************************
作者:Alfeim
题目:根据前序和后序遍历构造二叉树
时间消耗:12ms
解题思路:递归
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
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        int n = pre.size();
        if(n == 0) return nullptr;
        
        return Solve(pre,post,0,n-1,0,n-1);
    }
    
    TreeNode* Solve(vector<int>& pre, vector<int>& post,int prbegin, int prend, int pobegin ,int poend){
        
        if(prbegin > prend || pobegin > poend) return nullptr;
        

        TreeNode* root = new TreeNode(pre[prbegin]);
        
        if(prbegin == prend) return root;
 
        int index = 0;
        for(;pre[index] != post[poend-1];index++);
        
        root->left  = Solve(pre , post , prbegin + 1 , index - 1 , pobegin , pobegin + index - prbegin - 2);
        root->right = Solve(pre , post , index , prend , pobegin + index - prbegin - 1 ,  poend - 1);
       
        return root;
        
    }
};
