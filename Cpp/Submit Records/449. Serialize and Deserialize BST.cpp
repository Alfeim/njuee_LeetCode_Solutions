/********************************************
作者:Alfeim
题目:序列化和反序列化二叉搜索树
时间消耗:52ms
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
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        vector<string> tmp;
        Solve(root,tmp);
        string res;
        for(auto i : tmp) res += i;
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int n = data.size();
        queue<string> numbers;
        for(int i = 0 ; i < n ; ++i){
            if( data[i] == ',')
                continue;
            string number;
            while(data[i] != ','){
                number += data[i++];
            }
            numbers.push(number);
        }
        
        return rSolve(numbers);
        
    }
    
    void Solve(TreeNode* root,vector<string>& tmp){
        if(!root){
            tmp.push_back("#,");
            return;
        }
        
        tmp.push_back(to_string(root->val) + ',');
        Solve(root->left,tmp);
        Solve(root->right,tmp);
    }
    
    TreeNode* rSolve(queue<string> &numbers){
        if(numbers.empty()) return nullptr;
        
        auto cur = numbers.front();
        numbers.pop();
        
        if(cur == "#") return nullptr;
        
        int val = stoi(cur);
        TreeNode* root= new TreeNode(val);
        
        root->left = rSolve(numbers);
        root->right = rSolve(numbers);
        
        return root;
        
        
    }
    
    
    
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
