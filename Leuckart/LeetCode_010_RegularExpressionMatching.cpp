/**************************************************
	> File Name:  LeetCode_010_RegularExpressionMatching.cpp
	> Author:     Leuckart
	> Time:       2019-06-09 15:04
**************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	bool isMatch(string s, string p)
	{
		if (!s.length() && !p.length())
		{
			return true;
		}
		if (s.length() && !p.length())
		{
			return false;
		}

		if (!s.length())
		{
			if (p.length() % 2 == 1)
			{
				return false;
			}
			int p_half = p.length() / 2;
			for (int i = 0; i < p_half; i++)
			{
				if (p[2 * i + 1] != '*')
				{
					return false;
				}
			}
			return true;
		}

		if (p.length() >= 2 && p[1] == '*')
		{
			if (isMatch(s.substr(0), p.substr(2)))
			{
				return true;
			}

			for (int i = 1; (s[i - 1] == p[0]) || (p[0] == '.'); i++)
			{
				if (isMatch(s.substr(i), p.substr(2)))
					return true;
				else if (i == s.length())
					return false;
			}
		}
		else
		{
			if (s[0] == p[0] || p[0] == '.')
				return isMatch(s.substr(1), p.substr(1));
		}
		return false;
	}

	bool isMatch_DynamicProgramming(string s, string p)
	{
		vector<vector<bool>> match(s.length() + 3, vector<bool>(p.length() + 3, false));

		match[0][0] = true;
		match[1][1] = s[0] == p[0] || p[0] == '.';

		for (int j = 2; j < p.length() + 1; j += 2)
		{
			match[0][j] = match[0][j - 2] && p[j - 1] == '*';
		}

		for (int i = 1; i < s.length() + 1; i++)
		{
			for (int j = 2; j < p.length() + 1; j++)
			{
				if (p[j - 1] != '*')
				{
					match[i][j] = match[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
				}
				else
				{
					match[i][j] = match[i][j - 2] || (match[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'));
				}
			}
		}
		return match[s.length()][p.length()];
	}
};

int main()
{
	Solution sol;
	cout << sol.isMatch("aa", "a*") << endl;
	return 0;
}
