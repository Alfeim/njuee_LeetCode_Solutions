/********************************************
作者:Alfeim
题目:不含连续1的非负整数
时间消耗:4ms
解题思路:DP

对于一个n位数,小于或等于其位数的所有数中,不含连续1
的情况可以分为两种:

1.n位数
2.小于等于n-1位的数

由于能含有连续的1,所以n位数不含连续1的情况开头必然是
10,所以n位数不含连续1的情况与 “小于等于n-2位数不含
连续1的情况下同”

我们用dp[n]表示小于等于n位数中不含连续1的个数,可以得到
dp[n] = dp[n-1] + dp[n-2](其实就是斐波那契数列)


那么,现在已经给定了一个数,假定其有n位.
现在也有两种情况:

1.当前数的二进制以11开头
2.当前数的二进制以10开头

因为一个n位且不含连续1的数最大情况就是10顺序排列的数,
如果是11开头必然已经大于这个上界,所以开头为11的情况也
就是对应于dp[n]了.

而如果是以10开头,我们没法确定当前数是否超过了上界,因此
其也就对应于dp[n-1] + 递归求解当前数的低n-2位;

********************************************/

class Solution {
public:
    int findIntegers(int num) {
      vector<int> dp(33,0);
      dp[0] = 1;
      dp[1] = 2;
      for(int i =  2 ; i <= 32 ; ++i) dp[i] = dp[i-1] + dp[i-2];
      return Solve(num,dp);
    }

    int Solve(int num,vector<int> &dp){
      if(num == 0) return 1;
      if(num == 1) return 2;
      int bits = 0;
      while(num >> bits) bits++;
      
      if(num >> (bits - 2) == 3) return dp[bits];
      
      int mask = (1 << (bits - 1)) - 1;
      return dp[bits-1] + Solve(num&mask,dp);

    }
  
  
};
