/********************************************
作者:Alfeim
题目:删除一次得到子数组最大和
时间消耗:12ms
解题思路:DP
原始状态空间为 dp[i][j] 表示以下标i为结尾的连续子序列，已删除j个字符的情况下的最大和

那么当j为0时,实际上就是股票问题的基本情况(等价于求一个连续子序列的最大和)--》用一个sum变量统计当前和，当sum小于0时即置为0；

当j为1时，存在转移方程：dp[i][1] = max(dp[i-1][0],dp[i-1][1] + arr[i])----》即要么删除最后一个元素，要么保留最后一个元素

我们可以看到，实际上当前时刻状态(i)仅仅与上一时刻有关(i-1)，而且状态1仅仅与状态0有关，因此我们可以优化空间复杂度， 仅仅用两个变量表示！
********************************************/
class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();

        int dp_1 = 0;   
        int dp_0 = arr[0];
        
        int tmpMax = arr[0];
        int sum = arr[0];
        if(sum < 0 ) sum = 0;

        int tmp = 0;
        for(int i = 1 ; i < n ; ++i){
            sum += arr[i];
            tmp = dp_0;
            dp_0 = sum;
            dp_1 = max(dp_1 + arr[i],tmp);
            tmpMax = max(tmpMax,max(dp_1,dp_0));
            if(sum < 0) sum = 0;
        }

        return tmpMax;

    }
};
