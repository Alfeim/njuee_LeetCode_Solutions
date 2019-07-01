/**************************************************
	> File Name:  LeetCode_001_TwoSum.cpp
	> Author:     Leuckart
	> Time:       2019-04-10 16:09
**************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> twoSum(vector<int> &nums, int target)
	{
		vector<int> ans;
		for (int i = 0; i < nums.size() - 1; i++)
		{
			for (int j = i + 1; j < nums.size(); j++)
			{
				if (nums[i] + nums[j] == target)
				{
					ans = vector<int>{i, j};
				}
			}
		}
		return ans;
	}
};

int main()
{
	Solution sol;
	return 0;
}
