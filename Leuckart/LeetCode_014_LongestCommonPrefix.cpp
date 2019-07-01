/**************************************************
	> File Name:  LeetCode_014_LongestCommonPrefix.cpp
	> Author:     Leuckart
	> Time:       2019-04-12 05:01
**************************************************/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
	string longestCommonPrefix(vector<string> &strs)
	{
		if (strs.size() == 0)
		{
			return "";
		}
		string Ans = "";
		int pos = 0;
		while (1)
		{
			bool flag = true;
			if (pos >= strs[0].size())
			{
				break;
			}
			char ch = strs[0][pos];
			for (int str_iter = 0; str_iter < strs.size(); str_iter++)
			{
				if ((pos >= strs[str_iter].size()) || (ch != strs[str_iter][pos]))
				{
					flag = false;
					break;
				}
			}
			if (flag == false)
			{
				break;
			}
			Ans += ch;
			pos++;
		}
		return Ans;
	}
};

int main()
{
	Solution sol;
	return 0;
}
