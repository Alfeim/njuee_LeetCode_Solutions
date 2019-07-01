/**************************************************
	> File Name:  LeetCode_011_ContainerWithMostWater.cpp
	> Author:     Leuckart
	> Time:       2019-06-12 20:09
**************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	int maxArea(vector<int> &height)
	{
		int ans = 0;
		for (int l = 0, r = height.size() - 1; r > l;)
		{
			int temp = (r - l) * (height[r] < height[l] ? height[r] : height[l]);
			ans = ans > temp ? ans : temp;
			if (height[l] < height[r])
			{
				l++;
			}
			else
			{
				r--;
			}
		}
		return ans;
	}
};

int main()
{
	Solution sol;
	vector<int> v = {1, 8, 6, 2, 5, 4, 8, 3, 7};
	cout << sol.maxArea(v) << endl;
	return 0;
}
