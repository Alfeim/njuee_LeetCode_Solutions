/**************************************************
	> File Name:  LeetCode_020_ValidParentheses.cpp
	> Author:     Leuckart
	> Time:       2019-04-12 15:48
**************************************************/

#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

class Solution
{
public:
	bool isValid(string s)
	{
		stack<char> sta;

		for (char iter : s)
		{
			if ((!sta.empty()) && ((iter - sta.top() == 1) || (iter - sta.top() == 2)))
			{
				sta.pop();
			}
			else
			{
				sta.push(iter);
			}
		}
		return sta.empty();
	}
};

int main()
{
	Solution sol;
	return 0;
}
