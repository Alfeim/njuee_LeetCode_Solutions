/**************************************************
	> File Name:  LeetCode_145_BinaryTreePostorderTraversal.cpp
	> Author:     Leuckart
	> Time:       2019-04-18 17:26
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
	vector<int> postorderTraversal(TreeNode *root)
	{
		vector<int> Ans;
		stack<TreeNode *> save;
		save.push(root);
		TreeNode *ptr = root;
		if (ptr->left)
		{
			ptr = ptr->left;
		}
		else
		{
			ptr = ptr->right;
		}

		while ((ptr->left || ptr->right) && !save.empty())
		{
			if (ptr->left || ptr->right)
			{
				save.push(ptr);
				if (ptr->left)
				{
					ptr = ptr->left;
				}
				else
				{
					ptr = ptr->right;
				}
			}
			else
			{
				Ans.push_back(ptr->val);
				ptr = save.top();
				save.pop();
			}
		}
		return Ans;
	}
};

int main()
{
	Solution sol;
	return 0;
}
