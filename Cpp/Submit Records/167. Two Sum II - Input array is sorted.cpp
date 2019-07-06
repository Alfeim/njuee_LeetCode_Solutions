/********************************************
作者:Alfeim
题目:两数之和2-输入有序数组
时间消耗:4ms
解题思路:双指针法,求解X数之和的通用方式,时间复杂度
为O(N^(X-1));
********************************************/
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int first = 0;
        int second = numbers.size()-1;
        for(;first < second && numbers[first] + numbers[second] != target;){
            if(numbers[first] + numbers[second] < target)
                first++;
            else if(numbers[first] + numbers[second] > target)
                second--;
        }
        
        vector<int> res;
        res.push_back(first+1);
        res.push_back(second+1);
        return res;   
    }
};
