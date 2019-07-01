/**************************************************
	> File Name:  LeetCode_050_Pow.cpp
	> Author:     Leuckart
	> Time:       2019-06-27 19:43
**************************************************/

#include <iostream>
#include <climits>
using namespace std;

class Solution
{
public:
	double myPow(double x, int n)
	{
		double ans = 1;
		int extra = 1;
		if (n == INT_MIN)
		{
			n++;
			extra = x;
		}

		bool flag = n > 0;
		n = flag ? n : -n;

		int exp[32];
		int index = 0;
		while (n > 0)
		{
			exp[index] = n % 2;
			index++;
			n /= 2;
		}

		for (int i = index - 1; i >= 0; i--)
		{
			ans *= exp[i] ? x : 1;
			if (i >= 1)
			{
				ans *= ans;
			}
		}

		ans *= extra;
		return flag ? ans : 1 / ans;
	}
};

int main()
{
	Solution sol;
	return 0;
}