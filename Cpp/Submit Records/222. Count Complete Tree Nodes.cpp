/********************************************
作者:Alfeim
题目:完全二叉树的节点个数
时间消耗:36ms
解题思路:回溯/广度优先层次遍历
********************************************/
/***递归***/
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(!root)
            return 0;
        
        if(!root->left)
            return 1;
        
        if(!root->right)
            return 2;
        
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
  
};

/***广优***/
class Solution {
public:
    queue<TreeNode*> Q;
    int countNodes(TreeNode* root) {
        if(!root)
            return 0;
        
        bool isLast = false;
        int res = 0;
        int Level = 0;
        Q.push(root);
        
        while(!Q.empty()){
            Level++;
            int size = Q.size();
            while(size--){
                auto node = Q.front();
                Q.pop(); 
                if(isLast)
                    continue;
                if( !node->left || !node->right)
                    isLast = true;           
                if(node->left)
                    Q.push(node->left);    
                if(node->right)
                    Q.push(node->right);
            }   
            
            if(isLast){
                res = Q.size() + pow(2,Level)-1;
                break;
            }
        }
        
        return res;
    }
};
