/**************************************************
	> File Name:  LeetCode_029_DivideTwoIntegers.cpp
	> Author:     Leuckart
	> Time:       2019-06-29 19:00
**************************************************/

#include <iostream>
#include <climits>
using namespace std;

class Solution
{
public:
	int divide(int dividend, int divisor)
	{
		int ans = 0;
		bool flag = (dividend >= 0) ^ (divisor >= 0); //0 means +

		if (dividend < 0)
		{
			dividend &= INT_MAX; //No INT_MIN
			dividend--;
			dividend ^= INT_MAX;
		}
		if (divisor < 0)
		{
			divisor &= INT_MAX; //No INT_MIN
			divisor--;
			divisor ^= INT_MAX;
		}

		if (divisor == INT_MIN)
		{
			return dividend == INT_MIN;
		}
		if (dividend == INT_MIN)
		{
			dividend = INT_MAX - divisor + 1;
			ans++;
		}

		while (1)
		{
			int bit = 0;
			while ((dividend >> (bit + 1)) >= divisor)
			{
				bit++;
			}
			ans += bit > 0 ? (1 << bit) : 0;
			dividend -= (bit > 0 ? (divisor << bit) : 0);
			if (bit == 0)
			{
				break;
			}
		}

		while (dividend >= divisor)
		{
			dividend -= divisor;
			if ((ans == INT_MAX) && (!flag))
			{
				break;
			}
			else if ((ans == INT_MAX) && (flag))
			{
				return INT_MIN;
			}
			ans++;
		}
		return flag == 0 ? ans : -ans;
	}
};

int main()
{
	Solution sol;
	return 0;
}
