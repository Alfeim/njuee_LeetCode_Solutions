/**************************************************
	> File Name:  LeetCode_018_4Sum.cpp
	> Author:     Leuckart
	> Time:       2019-07-01 16:49
**************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
	vector<vector<int>> fourSum(vector<int> &nums, int target)
	{
		vector<vector<int>> Ans;
		int n = nums.size();
		if (n < 4)
		{
			return Ans;
		}
		sort(nums.begin(), nums.end());

		for (int i = 0; i < n - 3; i++)
		{
			if (i > 0 && nums[i] == nums[i - 1])
				continue;
			if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target)
				break;
			if (nums[i] + nums[n - 3] + nums[n - 2] + nums[n - 1] < target)
				continue;

			for (int j = i + 1; j < n - 2; j++)
			{
				if (j > i + 1 && nums[j] == nums[j - 1])
					continue;
				if (nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target)
					break;
				if (nums[i] + nums[j] + nums[n - 2] + nums[n - 1] < target)
					continue;

				for (int left = j + 1, right = n - 1; left < right;)
				{
					int sum = nums[left] + nums[right] + nums[i] + nums[j];
					if (sum == target)
					{
						Ans.push_back(vector<int>{nums[i], nums[j], nums[left], nums[right]});
						do
						{
							left++;
						} while (nums[left] == nums[left - 1] && left < right);
						do
						{
							right--;
						} while (nums[right] == nums[right + 1] && left < right);
					}
					else if (sum < target)
					{
						left++;
					}
					else
					{
						right--;
					}
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
