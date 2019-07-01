/**************************************************
	> File Name:  LeetCode_017_LetterCombinations.cpp
	> Author:     Leuckart
	> Time:       2019-07-01 14:37
**************************************************/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
	vector<string> letterCombinations(string digits)
	{
		vector<string> Ans;

		if (digits.size() == 0)
		{
			return Ans;
		}
		vector<string> post = letterCombinations(digits.substr(1));

		vector<string> cur;
		switch (digits[0] - '0')
		{
		case 2:
			cur = {"a", "b", "c"};
			break;
		case 3:
			cur = {"d", "e", "f"};
			break;
		case 4:
			cur = {"g", "h", "i"};
			break;
		case 5:
			cur = {"j", "k", "l"};
			break;
		case 6:
			cur = {"m", "n", "o"};
			break;
		case 7:
			cur = {"p", "q", "r", "s"};
			break;
		case 8:
			cur = {"t", "u", "v"};
			break;
		case 9:
			cur = {"w", "x", "y", "z"};
			break;
		default:
			break;
		}

		for (int i = 0; i < cur.size(); i++)
		{
			for (int j = 0; j < post.size(); j++)
			{
				Ans.push_back(cur[i] + post[j]);
			}
		}

		return post.size() ? Ans : cur;
	}
};

int main()
{
	Solution sol;
	return 0;
}
