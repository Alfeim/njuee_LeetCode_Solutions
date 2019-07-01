/**************************************************
	> File Name:  LeetCode_007_ReverseInteger.cpp
	> Author:     Leuckart
	> Time:       2019-04-10 23:06
**************************************************/

#include <iostream>
#include <climits>

class Solution
{
public:
	int reverse(int x)
	{
		bool is_negetive = x < 0;
		long posx = (is_negetive ? -long(x) : long(x));

		long Ans = 0;
		while (posx)
		{
			Ans = 10 * Ans + posx % 10;
			posx /= 10;
		}
		if (is_negetive)
		{
			return (Ans - 1 > INT_MAX) ? 0 : -Ans;
		}
		else
		{
			return (Ans > INT_MAX) ? 0 : Ans;
		}
	}
};

int main()
{
	Solution sol;
	return 0;
}
