/**************************************************
	> File Name:  LeetCode_016_3SumClosest.cpp
	> Author:     Leuckart
	> Time:       2019-07-01 13:50
**************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
	int threeSumClosest(vector<int> &nums, int target)
	{
		int Diff = nums[0] + nums[1] + nums[2] - target;
		sort(nums.begin(), nums.end());

		for (int cur = 0; cur < nums.size() - 2; cur++)
		{
			if (cur > 0 && nums[cur] == nums[cur - 1])
			{
				continue;
			}

			int reverse = target - nums[cur];
			int left = cur + 1, right = nums.size() - 1;

			while (left < right)
			{
				int diff_temp = nums[left] + nums[right] - reverse;
				if (abs(diff_temp) < abs(Diff))
				{
					Diff = diff_temp;
				}
				else if (diff_temp < 0)
				{
					left++;
				}
				else
				{
					right--;
				}
			}
		}
		return target + Diff;
	}
};

int main()
{
	Solution sol;
	return 0;
}
