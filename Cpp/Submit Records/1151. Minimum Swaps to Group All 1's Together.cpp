/********************************************
作者:Alfeim
题目:最少交换次数来组合所有1
时间消耗:80ms
解题思路:滑动窗口
********************************************/
class Solution {
public:
    int minSwaps(vector<int>& data) {
        int n = data.size();
        vector<int> PreCount(n+1,0);
        
        //先计算1的前缀个数
        for(int i = 0 ; i < n ; ++i) PreCount[i+1] = PreCount[i] + data[i];

        int count_one = PreCount[n];
        int res = n+1;

        //维护一个大小与1的个数相等的窗口,从左向右滑动,每个位置下需要交换的次数为：1的总个数减去窗口内1的个数
        for(int i = count_one - 1 ; i < n ; ++i){
            res = min(res,count_one - PreCount[i+1] + PreCount[i + 1 - count_one]);
        }

        return res;
    }
};
