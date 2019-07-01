/**************************************************
	> File Name:  LeetCode_015_3Sum.cpp
	> Author:     Leuckart
	> Time:       2019-06-27 23:54
**************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
	vector<vector<int>> threeSum(vector<int> &nums)
	{
		vector<vector<int>> Ans;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size(); i++)
		{
			if (i > 0 && nums[i] == nums[i - 1])
				continue;
			int target = -nums[i];

			for (int left = i + 1, right = nums.size() - 1; left < right;)
			{
				if (nums[left] + nums[right] == target)
				{
					Ans.push_back({nums[i], nums[left], nums[right]});
					do
					{
						left++;
					} while (left < right && nums[left] == nums[left - 1]);

					do
					{
						right--;
					} while (left < right && nums[right] == nums[right + 1]);
				}
				else if (nums[left] + nums[right] < target)
				{
					left++;
				}
				else
				{
					right--;
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
