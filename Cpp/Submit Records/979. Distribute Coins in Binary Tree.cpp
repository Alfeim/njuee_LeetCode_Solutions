/********************************************
作者:Alfeim
题目:在二叉树中分配硬币
时间消耗:12ms
解题思路:DFS

对于每个结点 我们可以算出其“过载数” ： 即 以该结点为根的子树中的硬币数 减去 该子树的结点数目

我们遍历每个结点 算出其过载数，而在计算的每一步过程中，我们都让 过载的硬币 从左右结点 上升到 根结点，
那么我们在这一步所需要移动的步数也就相当于 左子树的过载数的绝对值 + 右子树的过载数的绝对值
（无论过载数是正式负数，要移动的步数都是等于绝对值，这一点很容易看出来）

最终，累计每次过载数“上移”所需的步数总和 也就是我们真正要移动的累计步数

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
    int res;
    int distributeCoins(TreeNode* root) {
        res = 0;
        dfs(root);
        return res;
    }

    
    int dfs(TreeNode* root){
        if(!root) return 0;
        
        int Leftcount = dfs(root->left);
        int Rightcount = dfs(root->right);
        
        res += abs(Leftcount) + abs(Rightcount);
        
        return Leftcount + Rightcount + root->val - 1;
    }
   
    

};
