/********************************************
作者:Alfeim
题目:二叉搜索树中的众数
时间消耗:48ms
解题思路:利用二叉搜索树的中序遍历递增的性质
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
    int tmp;
    int last;
    int count;
    bool flag;
    vector<int> res;
    vector<int> findMode(TreeNode* root) {
        if(!root) 
            return {};
        flag = false;
        last = 0,count = 0,tmp = 0;
        
        //利用中序遍历是递增的性质
        Solve(root);
        
        //处理最后的连续相等元素
        if(tmp > count){
            res.clear();
            res.push_back(last);
        }else if(tmp == count)
            res.push_back(last);
        
        return res;
        
    }
    
    void Solve(TreeNode* root){ 
        if(!root) return;
        
        Solve(root->left);
        
        if(flag){
            if(root->val == last) 
                tmp++;
            else if(root->val != last){
                if(tmp > count){
                    count = tmp;
                    res.clear();
                    res.push_back(last);
                }else if(tmp == count)
                    res.push_back(last);
            
                tmp = 1;
                last = root->val;
            }
        }else{
            last = root->val;
            tmp = 1;
            flag = true;
        }
        
        Solve(root->right);
    }
};
