/**************************************************
	> File Name:  LeetCode_168_ExcelSheetColumnTitle.cpp
	> Author:     Leuckart
	> Time:       2019-06-30 22:40
**************************************************/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
	string convertToTitle(int n)
	{
		string Ans = "";
		while (n > 0)
		{
			int div = n % 26;

			n /= 26;
			if (div == 0)
			{
				Ans += 'Z';
				n--;
			}
			else
			{
				Ans += div + 'A' - 1;
			}
		}
		reverse(Ans.begin(), Ans.end());
		return Ans;
	}
};

int main()
{
	Solution sol;
	return 0;
}
