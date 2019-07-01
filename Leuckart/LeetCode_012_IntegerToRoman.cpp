/**************************************************
	> File Name:  LeetCode_012_IntegerToRoman.cpp
	> Author:     Leuckart
	> Time:       2019-06-12 20:24
**************************************************/

#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
	string intToRoman(int num)
	{
		string ans = "";
		int M_Num = num / 1000;
		for (int i = 0; i < M_Num; i++)
			ans += "M";
		num -= M_Num * 1000;

		if (num >= 500)
		{
			if (num >= 900)
			{
				ans += "CM";
				num -= 900;
			}
			else
			{
				ans += "D";
				num -= 500;
			}
		}

		if (num >= 400)
		{
			ans += "CD";
			num -= 400;
		}
		else if (num >= 100)
		{
			int C_Num = num / 100;
			for (int i = 0; i < C_Num; i++)
				ans += "C";
			num -= C_Num * 100;
		}

		if (num >= 50)
		{
			if (num >= 90)
			{
				ans += "XC";
				num -= 90;
			}
			else
			{
				ans += "L";
				num -= 50;
			}
		}

		if (num >= 40)
		{
			ans += "XL";
			num -= 40;
		}
		else if (num >= 10)
		{
			int X_Num = num / 10;
			for (int i = 0; i < X_Num; i++)
				ans += "X";
			num -= X_Num * 10;
		}

		switch (num)
		{
		case 9:
			ans += "IX";
			return ans;
		case 8:
			ans += "VIII";
			return ans;
		case 7:
			ans += "VII";
			return ans;
		case 6:
			ans += "VI";
			return ans;
		case 5:
			ans += "V";
			return ans;
		case 4:
			ans += "IV";
			return ans;
		case 3:
			ans += "III";
			return ans;
		case 2:
			ans += "II";
			return ans;
		case 1:
			ans += "I";
			return ans;

		default:
			return ans;
		}
	}
};

int main()
{
	Solution sol;
	cout << sol.intToRoman(1994) << endl;
	return 0;
}
