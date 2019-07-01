/**************************************************
	> File Name:  LeetCode_005_LongestPalindromicSubstring.cpp
	> Author:     Leuckart
	> Time:       2019-04-13 16:14
**************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	string longestPalindrome(string s)
	{
		if (s.size() <= 1)
		{
			return s;
		}

		string exs(2 * s.length() + 2, '#');
		exs[0] = '$';
		for (int i = 0; i < s.length(); i++)
		{
			exs[2 * i + 2] = s[i];
		}

		vector<int> Flen(exs.length(), 0);

		int j = 1;
		Flen[0] = Flen[1] = 1;
		int maxRange = 1;
		int maxLong = 1;
		int mid_pos;

		for (int i = 2; i < exs.length(); i++)
		{
			if (i > maxRange)
			{
				Flen[i] = 1;
			}
			else
			{
				Flen[i] = min(Flen[2 * j - i], maxRange - i);
			}

			while (exs[i - Flen[i]] == exs[i + Flen[i]])
			{
				Flen[i]++;
			}
			if (maxRange < i + Flen[i])
			{
				j = i;
				maxRange = i + Flen[i];
			}

			if (maxLong < Flen[i] - 1)
			{
				maxLong = Flen[i] - 1;
				mid_pos = i;
			}
		}
		if (maxLong == 1)
		{
			return s.substr(0, 1);
		}
		return s.substr((mid_pos - Flen[mid_pos]) / 2, Flen[mid_pos] - 1);
	}
};

int main()
{
	Solution sol;
	//cout << sol.longestPalindrome("cbbd");
	cout << sol.longestPalindrome("xabaabad") << endl;
	cout << sol.longestPalindrome("bab") << endl;
	cout << sol.longestPalindrome("a") << endl;
	cout << sol.longestPalindrome("ac") << endl;
	return 0;
}
