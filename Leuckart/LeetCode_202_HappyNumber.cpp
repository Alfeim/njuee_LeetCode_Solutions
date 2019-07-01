/**************************************************
	> File Name:  LeetCode_202_HappyNumber.cpp
	> Author:     Leuckart
	> Time:       2019-06-28 07:06
**************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
	bool isHappy(int n)
	{
		vector<int> ans;
		while (find(ans.begin(), ans.end(), n) == ans.end())
		{
			ans.push_back(n);
			int square_sum = 0;
			while (n > 0)
			{
				square_sum += (n % 10) * (n % 10);
				n /= 10;
			}
			n = square_sum;
		}
		return find(ans.begin(), ans.end(), 1) != ans.end();
	}
};

int main()
{
	Solution sol;
	return 0;
}
