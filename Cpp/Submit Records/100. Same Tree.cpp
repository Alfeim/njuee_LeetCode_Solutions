/********************************************
作者:Alfeim
题目:相同的树
时间消耗:4ms
解题思路:递归
********************************************/
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q )
            return true;
        
        if( (p && !q) || (!p && q))
            return false;
        
        if(p->val != q->val)
            return false;
        
        return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);

    }
};
