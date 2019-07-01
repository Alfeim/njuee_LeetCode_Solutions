/**************************************************
	> File Name:  LeetCode_028_ImplementStrStr.cpp
	> Author:     Leuckart
	> Time:       2019-06-23 21:49
**************************************************/

#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
	int strStr(string haystack, string needle)
	{
		for (int i = 0; i < haystack.size(); i++)
		{
			bool flag = true;
			for (int j = 0; j < needle.size(); j++)
			{
				if (haystack[i + j] != needle[j])
				{
					flag = false;
					break;
				}
			}
			if (flag)
			{
				return i;
			}
		}
		return needle.size() > 0 ? -1 : 0;
	}
};

int main()
{
	Solution sol;
	return 0;
}
