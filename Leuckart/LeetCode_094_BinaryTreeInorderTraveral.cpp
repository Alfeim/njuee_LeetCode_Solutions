/**************************************************
	> File Name:  LeetCode_094_BinaryTreeInorderTraveral.cpp
	> Author:     Leuckart
	> Time:       2019-06-07 18:30
**************************************************/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
	vector<int> inorderTraversal(TreeNode *root)
	{
		stack<TreeNode *> saved;
		vector<int> ans;

		TreeNode *cur = root;
		while (!(cur == NULL && saved.empty()))
		{
			if (cur == NULL)
			{
				cur = saved.top();
				saved.pop();
				ans.push_back(cur->val);
				cur = cur->right;
				continue;
			}
			while (cur->left != NULL)
			{
				saved.push(cur);
				cur = cur->left;
			}
			ans.push_back(cur->val);
			cur = cur->right;
		}
		return ans;
	}
};

int main()
{
	Solution sol;
	return 0;
}
