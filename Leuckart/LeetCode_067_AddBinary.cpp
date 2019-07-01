/**************************************************
	> File Name:  LeetCode_067_AddBinary.cpp
	> Author:     Leuckart
	> Time:       2019-06-28 00:37
**************************************************/

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class Solution
{
public:
	string addBinary(string a, string b)
	{
		string ans = "";
		int flag = 0;

		for (int index = 0; index < a.size() || index < b.size(); index++)
		{
			int ai = index < a.size() ? a[a.size() - 1 - index] - '0' : 0;
			int bi = index < b.size() ? b[b.size() - 1 - index] - '0' : 0;
			int ci = ai + bi + flag;

			flag = ci > 1;
			ci -= ci > 1 ? 2 : 0;
			ans += ci + '0';
		}
		if (flag)
		{
			ans += '1';
		}
		reverse(ans.begin(), ans.end());
		return ans;
	}
};

int main()
{
	Solution sol;
	return 0;
}
