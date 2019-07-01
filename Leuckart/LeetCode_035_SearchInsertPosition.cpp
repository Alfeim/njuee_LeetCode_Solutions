/**************************************************
	> File Name:  LeetCode_035_SearchInsertPosition.cpp
	> Author:     Leuckart
	> Time:       2019-07-01 05:07
**************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	int searchInsert(vector<int> nums, int target)
	{
		if (nums.size() == 0)
		{
			return 0;
		}

		int left = 0, right = nums.size() - 1, pos;
		while (left + 1 < right)
		{
			pos = (left + right) / 2;
			if (nums[pos] < target)
			{
				left = pos;
			}
			else if (nums[pos] > target)
			{
				right = pos;
			}
			else
			{
				return pos;
			}
		}

		if (target <= nums[left])
		{
			return left;
		}
		if (target <= nums[right])
		{
			return right;
		}
		return right + 1;
	}
};

int main()
{
	Solution sol;
	return 0;
}