/********************************************
作者:Alfeim
题目:最后一块石头的重量2
时间消耗:4ms

解题思路:DP

实质是一道01背包问题

这个问题可以等价于把石子分为两堆,要使得两堆之差尽量小,也就是尽量将其中一堆的大小分配到总和的一半

所以容量V就是石子重量和的一半

********************************************/
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0;
        for(auto i : stones) sum += i;
        
        int MaxV = sum/2;
        int n = stones.size();
        
        vector<int> dp(MaxV + 1,0);
        
        for(int i = 0 ; i < n ; ++i){
            for(int j = MaxV ; j >= stones[i] ; --j){
                dp[j] = max(dp[j],dp[j - stones[i]] + stones[i]);   
            }
        }
        
        return sum - 2*dp[MaxV];
        
    }
};
