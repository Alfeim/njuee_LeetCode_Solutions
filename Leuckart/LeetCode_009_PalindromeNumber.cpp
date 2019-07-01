/**************************************************
	> File Name:  LeetCode_009_PalindromeNumber.cpp
	> Author:     Leuckart
	> Time:       2019-04-11 18:21
**************************************************/

#include <iostream>

class Solution
{
public:
	bool isPalindrome(int x)
	{
		long x_fixed = x, x_rev = 0;
		while (x)
		{
			x_rev = x_rev * 10 + x % 10;
			x /= 10;
		}
		return (x_fixed == x_rev) && (x_fixed >= 0);
	}
};

int main()
{
	Solution sol;
	return 0;
}
