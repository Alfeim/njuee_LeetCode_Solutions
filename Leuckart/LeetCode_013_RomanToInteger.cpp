/**************************************************
	> File Name:  LeetCode_013_RomanToInteger.cpp
	> Author:     Leuckart
	> Time:       2019-04-11 18:30
**************************************************/

#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
	int romanToInt(string s)
	{
		int Value[26];
		Value['I' - 'A'] = 1;
		Value['V' - 'A'] = 5;
		Value['X' - 'A'] = 10;
		Value['L' - 'A'] = 50;
		Value['C' - 'A'] = 100;
		Value['D' - 'A'] = 500;
		Value['M' - 'A'] = 1000;

		int Ans = 0;
		for (auto iter = s.begin(); iter != s.end() - 1; iter++)
		{
			Ans += (Value[*iter - 'A'] < Value[*(iter + 1) - 'A']) ? (-Value[*iter - 'A']) : (Value[*iter - 'A']);
		}
		return Ans + Value[*(s.rbegin()) - 'A'];
	}
};

int main()
{
	Solution sol;
	return 0;
}
