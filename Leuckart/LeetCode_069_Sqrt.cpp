/**************************************************
	> File Name:  LeetCode_069_Sqrt.cpp
	> Author:     Leuckart
	> Time:       2019-06-28 01:12
**************************************************/

#include <iostream>
using namespace std;

class Solution
{
public:
	int mySqrt(int x)
	{
		if (x <= 0)
		{
			return 0;
		}

		int bit = 0;
		for (int x_copy = x; x_copy > 0; x_copy /= 2)
		{
			bit++;
		}

		long left = 1 << ((bit - 1) / 2);
		long right = 1 << ((bit + 1) / 2);
		long mid = (left + right) / 2;

		while (left < right - 1)
		{
			if (mid * mid <= x)
			{
				left = mid;
			}
			else
			{
				right = mid;
			}
			mid = (left + right) / 2;
		}
		return mid;
	}
};

int main()
{
	Solution sol;
	return 0;
}
