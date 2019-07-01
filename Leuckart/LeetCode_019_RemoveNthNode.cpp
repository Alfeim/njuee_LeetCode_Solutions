/**************************************************
	> File Name:  LeetCode_019_RemoveNthNode.cpp
	> Author:     Leuckart
	> Time:       2019-06-28 00:15
**************************************************/

#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
	ListNode *removeNthFromEnd(ListNode *head, int n)
	{
		// No Bound Processing.
		ListNode *leftleft = head, *left = head, *right = head;

		for (int i = 0; i < n; i++)
		{
			right = right->next;
		}
		// Now that you said "Given n will always be valid", HaHaHa, No Need to Check!
		if (right == nullptr)
		{
			return head->next;
		}

		// Lazy Execution.
		do
		{
			left = left->next;
			right = right->next;
		} while ((right != nullptr) && (leftleft = leftleft->next));

		leftleft->next = left->next;
		return head;
	}
};

int main()
{
	Solution sol;
	return 0;
}
