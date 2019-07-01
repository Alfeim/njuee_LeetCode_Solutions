/**************************************************
	> File Name:  LeetCode_027_RemoveElement.cpp
	> Author:     Leuckart
	> Time:       2019-06-09 14:50
**************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	int removeElement(vector<int> &nums, int val)
	{
		int count = nums.size();
		for (auto iter = nums.begin(); iter != nums.end();)
		{
			if (*iter == val)
			{
				iter = nums.erase(iter);
				count--;
			}
			else
			{
				iter++;
			}
		}
		return count;
	}
};

int main()
{
	Solution sol;
	return 0;
}
