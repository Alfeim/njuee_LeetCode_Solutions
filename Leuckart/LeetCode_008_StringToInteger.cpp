/**************************************************
	> File Name:  LeetCode_008_StringToInteger.cpp
	> Author:     Leuckart
	> Time:       2019-06-08 17:53
**************************************************/

#include <iostream>
#include <string>
#include <climits>
using namespace std;

class Solution
{
public:
	int myAtoi(string str)
	{
		int ans = 0;
		bool neg = false;
		bool begin = false;
		for (auto ch : str)
		{
			if (ch == ' ' && !begin)
			{
				continue;
			}
			else if ((ch == '-' || ch == '+') && ans == 0 && !begin)
			{
				begin = true;
				neg = (ch == '-');
			}
			else if (ch >= '0' && ch <= '9')
			{
				begin = true;
				bool flag1 = ans > INT_MAX / 10;
				bool flag2 = (ans == INT_MAX / 10) && (ch - '0' > INT_MAX % 10);
				if (flag1 || flag2)
				{
					return neg ? INT_MIN : INT_MAX;
				}
				else
				{
					ans = ans * 10 + (ch - '0');
				}
			}
			else
			{
				break;
			}
		}
		return ans * (neg ? -1 : 1);
	}
};

int main()
{
	Solution sol;
	return 0;
}
