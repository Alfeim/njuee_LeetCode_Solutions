/**************************************************
	> File Name:  LeetCode_004_MedianOfTwoSortedArrays.cpp
	> Author:     Leuckart
	> Time:       2019-04-11 14:29
**************************************************/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution
{
public:
	double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
	{
		vector<int> List1 = (nums1.size() <= nums2.size()) ? nums1 : nums2;
		vector<int> List2 = (nums1.size() <= nums2.size()) ? nums2 : nums1;
		int len1 = List1.size();
		int len2 = List2.size();

		int left = 0, right = len1;
		int pos1, pos2;

		while (left <= right)
		{
			pos1 = (left + right) / 2;
			pos2 = (len1 + len2 + 1) / 2 - pos1;

			if ((pos1 < len1) && (List1[pos1] < List2[pos2 - 1]))
			{
				left = pos1 + 1;
			}
			else if ((pos1 > 0) && (List1[pos1 - 1] > List2[pos2]))
			{
				right = pos1 - 1;
			}
			else
			{
				int left_part = max(((pos1 == 0) ? INT_MIN : List1[pos1 - 1]), ((pos2 == 0) ? INT_MIN : List2[pos2 - 1]));
				int right_part = min(((pos1 == len1) ? INT_MAX : List1[pos1]), ((pos2 == len2) ? INT_MAX : List2[pos2]));
				return ((len1 + len2) % 2) ? left_part : (left_part + right_part) / 2.0;
			}
		}
	}
};

int main()
{
	Solution sol;
	return 0;
}
