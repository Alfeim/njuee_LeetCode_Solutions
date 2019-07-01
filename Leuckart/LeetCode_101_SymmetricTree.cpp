/**************************************************
	> File Name:  LeetCode_101_SymmetricTree.cpp
	> Author:     Leuckart
	> Time:       2019-06-07 22:11
**************************************************/

#include <iostream>
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
	bool isSymmetric(TreeNode *root)
	{
		if (root == NULL)
		{
			return true;
		}
		TreeNode *pl = root->left;
		TreeNode *pr = root->right;
		stack<TreeNode *> stack_l, stack_r;

		while (!(pl == NULL && pr == NULL && stack_l.empty() && stack_r.empty()))
		{
			if ((pl == NULL && pr != NULL) || (pl != NULL && pr == NULL))
			{
				return false;
			}
			if (pl == NULL && pr == NULL)
			{
				pl = stack_l.top();
				stack_l.pop();

				pr = stack_r.top();
				stack_r.pop();

				if (pl->val != pr->val)
				{
					return false;
				}
				pl = pl->right;
				pr = pr->left;
				continue;
			}
			while (pl->left != NULL)
			{
				stack_l.push(pl);
				pl = pl->left;
				if (pr->right == NULL)
				{
					return false;
				}
				else
				{
					stack_r.push(pr);
					pr = pr->right;
				}
			}
			if (pr->right != NULL)
			{
				return false;
			}

			if (pl->val != pr->val)
			{
				return false;
			}
			pl = pl->right;
			pr = pr->left;
		}
		return true;
	}
};

int main()
{
	Solution sol;
	return 0;
}
