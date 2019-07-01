/**************************************************
	> File Name:  LeetCode_066_PlusOne.cpp
	> Author:     Leuckart
	> Time:       2019-06-29 21:12
**************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
	vector<int> plusOne(vector<int> &digits)
	{
		bool flag = true;
		for (int i = digits.size() - 1; i >= 0; i--)
		{
			digits[i] += flag;
			flag = false;
			if (digits[i] > 9)
			{
				digits[i] -= 10;
				flag = true;
			}
		}
		if (flag)
		{
			digits.insert(digits.begin(), 1);
		}
		return digits;
	}
};

int main()
{
	Solution sol;
	return 0;
}
