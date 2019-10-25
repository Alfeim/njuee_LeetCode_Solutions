/********************************************
作者:Alfeim
题目:监控二叉树
时间消耗:12ms/84ms
解题思路:贪心/DP
********************************************/

//贪心算法 后序遍历
//用0 表示不确定状态，即对其他结点没有影响。如果某个结点的子节点均为0，则该节点状态置为1
//1表示未监控，如果某个节点的任何子节点为1，则说明该节点需要添置摄像头，让摄像头数+1，并返回2
//2表示已监控
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
    int camera;
    int minCameraCover(TreeNode* root) {
        camera = 0;
        if(dfs(root) == 1) camera++;
        return camera;
    }

    int dfs(TreeNode* root){
        if(!root) return 0;

        int l = dfs(root->left);
        int r = dfs(root->right);

        if(l + r == 0){
            return 1;
        }else if( l == 1 || r == 1){
            camera++;
            return 2;
        }
        
        return 0;
    }
};

//dp做法 这里状态空间是：当前结点、当前结点是否被覆盖、当前结点的父结点是否被覆盖
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
    map<TreeNode*,vector<vector<int>>> record;
    int minCameraCover(TreeNode* root) {
        //树中dp问题
        dfs(root,true,false);
        dfs(root,false,false);
        return min(record[root][1][0],record[root][0][0]);
    }

    int dfs(TreeNode* root,bool mycamera,bool fcamera){
        if(!root) return 0;
        if(!record.count(root)) record[root] = {{1001,1001},{1001,1001}};
       
        if(mycamera && !fcamera && record[root][1][0] != 1001) return record[root][1][0];
        else if(mycamera && fcamera && record[root][1][1] != 1001) return record[root][1][1];
        else if(!mycamera && fcamera && record[root][0][1] != 1001) return record[root][0][1];
        else if(!mycamera && !fcamera && record[root][0][0] != 1001) return record[root][0][0];

        int sum1,sum2,sum3,sum4;

        if(mycamera){
            sum1 = dfs(root->left,true,true);
            sum2 = dfs(root->left,false,true);
            sum3 = dfs(root->right,true,true);
            sum4 = dfs(root->right,false,true);
            record[root][1][1] = min(min(sum1 + sum3,sum1 + sum4),min(sum2 + sum3,sum2 + sum4)) + 1;
            record[root][1][0] = record[root][1][1];
            return record[root][1][0];
        }

            sum1 = dfs(root->left,true,false);
            sum2 = dfs(root->left,false,false);
            sum3 = dfs(root->right,true,false);
            sum4 = dfs(root->right,false,false);

            if(fcamera){
                record[root][0][1] = min(min(sum1 + sum3,sum1 + sum4),min(sum2 + sum3,sum2 + sum4));
                return record[root][0][1];
            }

            if(root->left && root->right){
                record[root][0][0] = min(min(sum1 + sum3,sum1 + sum4),sum2 + sum3);
            }else if(root->right){
                record[root][0][0] = sum3;
            }else if(root->left){
                record[root][0][0] = sum1;
            }

            return record[root][0][0];
           
    }
};
