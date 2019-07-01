/**************************************************
	> File Name:  LeetCode_043_MultiplyStrings.cpp
	> Author:     Leuckart
	> Time:       2019-06-30 21:38
**************************************************/

#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
	string multiply(string num1, string num2)
	{
		string Ans = "";
		for (int i = num2.size() - 1; i >= 0; i--)
		{
			int factor = num2[i] - '0';
			string temp = num1;
			int flag = 0;

			for (int j = temp.size() - 1; j >= 0; j--)
			{
				int mult = (temp[j] - '0') * factor + flag;

				temp[j] = '0' + mult % 10;
				flag = mult / 10;
			}

			if (flag)
			{
				temp.insert(temp.begin(), flag + '0');
			}

			temp.insert(temp.end(), num2.size() - 1 - i, '0');

			if (Ans.size() < temp.size())
			{
				string ans_temp = Ans;
				Ans = temp;
				temp = ans_temp;
			}

			int add_flag = 0;
			for (int k = 0; k < Ans.size(); k++)
			{
				int add_two = (Ans[Ans.size() - 1 - k] - '0') + (k >= temp.size() ? 0 : temp[temp.size() - 1 - k] - '0') + add_flag;

				Ans[Ans.size() - 1 - k] = '0' + add_two % 10;
				add_flag = add_two / 10;
			}
			if (add_flag)
			{
				Ans.insert(Ans.begin(), add_flag + '0');
			}
		}

		auto pos = Ans.find_first_not_of("0");
		return pos == Ans.npos ? "0" : Ans.substr(pos);
	}
};

int main()
{
	Solution sol;
	return 0;
}
