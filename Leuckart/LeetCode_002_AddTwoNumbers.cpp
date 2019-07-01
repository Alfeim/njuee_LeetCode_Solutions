/**************************************************
	> File Name:  LeetCode_002_AddTwoNumbers.cpp
	> Author:     Leuckart
	> Time:       2019-04-10 21:36
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
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
	{
		ListNode *Ans = new ListNode(0);
		ListNode *ptr = Ans;
		bool is_overflow = 0;

		while (1)
		{
			ptr->val = (l1 ? (l1->val) : 0) + (l2 ? (l2->val) : 0) + is_overflow;
			is_overflow = ptr->val > 9;

			if (is_overflow)
			{
				ptr->val -= 10;
			}

			l1 = l1 ? (l1->next) : NULL;
			l2 = l2 ? (l2->next) : NULL;
			if (!l1 && !l2)
			{
				ptr->next = is_overflow ? (new ListNode(1)) : NULL;
				break;
			}

			ptr->next = new ListNode(0);
			ptr = ptr->next;
		}
		return Ans;
	}
};

int main()
{
	Solution sol;
	return 0;
}
