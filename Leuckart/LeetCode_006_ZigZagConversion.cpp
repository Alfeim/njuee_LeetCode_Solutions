/**************************************************
	> File Name:  LeetCode_006_ZigZagConversion.cpp
	> Author:     Leuckart
	> Time:       2019-04-17 21:43
**************************************************/

#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
	string convert(string s, int numRows)
	{
		string Ans = "";
		if (numRows == 1)
		{
			return s;
		}
		int Loops = 2 * (numRows - 1);
		for (int i = 0; i < numRows; i++)
		{
			for (int j = 0; j < s.length(); j++)
			{
				if (j % Loops == i || j % Loops == Loops - i)
				{
					Ans += s.substr(j, 1);
				}
			}
		}
		return Ans;
	}
};

int main()
{
	Solution sol;
	return 0;
}
