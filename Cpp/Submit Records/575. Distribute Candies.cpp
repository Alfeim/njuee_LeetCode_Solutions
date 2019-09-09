/********************************************
作者:Alfeim
题目:分糖果
时间消耗:296ms
解题思路:没啥好说的...
********************************************/
class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        sort(candies.begin(),candies.end());
        int n = candies.size();
        int len = distance(candies.begin(),unique(candies.begin(),candies.end()));
        return min(len,n/2);
    }
};
