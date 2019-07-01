/**************************************************
	> File Name:  LeetCode_100_SameTree.cpp
	> Author:     Leuckart
	> Time:       2019-06-07 22:00
**************************************************/

#include <iostream>

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
	bool isSameTree(TreeNode *p, TreeNode *q)
	{
		if (p == NULL && q == NULL)
		{
			return true;
		}
		if ((p == NULL && q != NULL) || (p != NULL && q == NULL))
		{
			return false;
		}
		if (p->val == q->val)
		{
			return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
		}
		else
		{
			return false;
		}
	}
};

int main()
{
	Solution sol;
	return 0;
}
