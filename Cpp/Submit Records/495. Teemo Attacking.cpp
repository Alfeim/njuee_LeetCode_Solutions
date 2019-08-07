/********************************************
作者:Alfeim
题目:提莫攻击
时间消耗:60ms
解题思路:这真的配中等难度嘛..
********************************************/
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if(timeSeries.empty())
            return 0;
        long sum = duration;
        long last = timeSeries[0] + duration;
        int n = timeSeries.size();
        for(int i = 1 ; i < n ; ++i){
            if(timeSeries[i] >= last)
                sum += duration;
            else
                sum += duration - (last - timeSeries[i]);
            
            last = timeSeries[i] + duration;  
        }
        return sum;
    }
};
