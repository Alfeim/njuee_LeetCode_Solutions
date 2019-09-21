/********************************************
作者:Alfeim
题目:二叉树中所有距离为K的结点
时间消耗:8ms
解题思路:BFS
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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        unordered_map<int,vector<int>> Edges;
        unordered_set<int> record;
        vector<int> res;
        
        if(K == 0) return {target->val};
        
        CreateGraph(Edges,root);
        queue<int> Q;
        
        Q.push(target->val);
        record.insert(target->val);
        int distance = 0;
        
        while(!Q.empty()){
            int size = Q.size();
            
            while(size--){
                auto cur = Q.front();
                Q.pop();
                
                for(auto i : Edges[cur]){
                    if(!record.count(i)) {
                        record.insert(i);
                        Q.push(i);
                    }
                }
            }    
            
            distance++;
            if(distance == K) break;
        }
 
        while(!Q.empty()){
            res.push_back(Q.front());
            Q.pop();
        }
        
        return res;
        
        
    }
    
    void CreateGraph(unordered_map<int,vector<int>> &Edges,TreeNode* root){
        if(!root) return;
        
        if(root->left) {
            Edges[root->val].push_back(root->left->val);
            Edges[root->left->val].push_back(root->val);
        }
        
        if(root->right) {
            Edges[root->val].push_back(root->right->val);
            Edges[root->right->val].push_back(root->val);
        }
        
        CreateGraph(Edges,root->left);
        CreateGraph(Edges,root->right);
        
    }
    
};
