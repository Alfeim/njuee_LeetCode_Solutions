/********************************************
作者:Alfeim
题目:二叉搜索树迭代器
时间消耗:72ms
解题思路:栈;题目要求的O(1)复杂度实际是平均复杂度;
********************************************/
class BSTIterator {
public:
    BSTIterator(TreeNode* root){ 
        Save(root);
    }
    
    /** @return the next smallest number */
    int next() {
        auto cur = S.top();
        S.pop();
        Save(cur->right);
        return cur->val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !S.empty();
    } 
    void Save(TreeNode* root){
        if(!root)
            return;
        S.push(root);
        Save(root->left);
    }  
private:
    stack<TreeNode*> S;
    
};
