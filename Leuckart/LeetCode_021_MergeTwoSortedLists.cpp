/**************************************************
	> File Name:  LeetCode_021_MergeTwoSortedLists.cpp
	> Author:     Leuckart
	> Time:       2019-04-12 02:17
**************************************************/

#include <iostream>

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
	ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
	{
		ListNode *Ans = new ListNode(0);
		ListNode *ptr = Ans, *ptr1 = l1, *ptr2 = l2;

		while (ptr1 || ptr2)
		{
			if (ptr1 != l1 || ptr2 != l2)
			{
				ptr = ptr->next = new ListNode(0);
			}
			if ((!ptr2) || ((ptr1 != NULL) && (ptr1->val <= ptr2->val)))
			{
				ptr->val = ptr1->val;
				ptr1 = ptr1->next;
			}
			else
			{
				ptr->val = ptr2->val;
				ptr2 = ptr2->next;
			}
		}
		return (l1 != NULL || l2 != NULL) ? Ans : NULL;
	}
};

int main()
{
	Solution sol;
	return 0;
}
