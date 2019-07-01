/**************************************************
	> File Name:  LeetCode_026_RemoveDuplicatesFromSortedArray.cpp
	> Author:     Leuckart
	> Time:       2019-04-17 17:57
**************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	int removeDuplicates(vector<int> &nums)
	{
		int Ans = 1;

		for (auto iter = nums.begin() + 1; iter < nums.end();)
		{
			if (*iter == *(iter - 1))
			{
				iter = nums.erase(iter);
			}
			else
			{
				iter++;
				Ans++;
			}
		}
		return nums.empty() ? 0 : Ans;
	}
};

int main()
{
	Solution sol;
	return 0;
}
