/**************************************************
	> File Name:  LeetCode_003_LongestSubstring.cpp
	> Author:     Leuckart
	> Time:       2019-04-12 18:15
**************************************************/

#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
	int lengthOfLongestSubstring(string s)
	{
		int max_len = 0;
		int left = 0;
		for (int right = 1; right < s.size(); right++)
		{
			int search = s.find_first_of(s[right], left);

			if (search < right)
			{
				left = search + 1;
			}
			max_len = max(right - left + 1, max_len);
		}
		return (s.size() == 1) ? 1 : max_len;
	}
};

int main()
{
	Solution sol;
	return 0;
}
