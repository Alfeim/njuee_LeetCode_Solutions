/********************************************
作者:Alfeim
题目:区间和的个数
时间消耗:44ms
解题思路:利用前缀和的性质,维护一个递增的set
********************************************/
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int res = 0;
        int n = nums.size();
        multiset<long> prefix;
        prefix.insert(0);
        long sum = 0;
        for(int i = 0 ; i < n ; ++i){
            sum += nums[i];
            res += distance(prefix.lower_bound(sum - upper),prefix.upper_bound(sum - lower));
            prefix.insert(sum);
        }
        return res;
    }
};
