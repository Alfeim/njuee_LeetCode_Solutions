/********************************************
作者:Alfeim
题目:输出二叉树
时间消耗:8ms
解题思路:层次遍历、细节
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
    queue<TreeNode*> Q;
    vector<vector<string>> printTree(TreeNode* root) {
        if(!root) return {};
        int level = 0;
        bool flag = true;
        vector<string> List;
        Q.push(root);
        while(flag){
            level++;
            flag = false;
            int size = Q.size();
            while(size--){
                auto cur = Q.front();
                Q.pop();
                if(!cur){
                    List.push_back("*");
                    Q.push(nullptr);
                    Q.push(nullptr);
                }else{
                    List.push_back(to_string(cur->val));  
                    if(cur->left || cur->right) flag = true;
                    Q.push(cur->left);
                    Q.push(cur->right);
                }
            }
        }
        

        int width = pow(2,level) - 1;
        vector<vector<string>> res(level,vector<string>(width,""));
        int next_pos = 1;
        int cur_level = 1;
        int len = List.size();
        for(int i = 0 ; i < len ; ++i){
            if(i == next_pos){
                next_pos = 2 * i + 1;
                cur_level++;
            }
            update(res,List[i],level,cur_level,i);
        }
        return res;
   
    }
    
    
    void update(vector<vector<string>> &res,string &cur,int all_level,int cur_level,int cur_pos){
        int begin = pow(2,all_level - cur_level) - 1;
        int pos = cur_pos - pow(2,cur_level-1) + 1;
        pos = pos * (pow(2,all_level - cur_level + 1)) + begin;
        if(cur != "*") res[cur_level-1][pos] += cur;
    }
};
