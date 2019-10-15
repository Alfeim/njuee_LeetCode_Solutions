/********************************************
作者:Alfeim
题目:DI的有效排列
时间消耗:68ms
解题思路:DP
dp[i][j] 长度为i + 1的数组,以顺序下标 j (所谓顺序下标即按小到大顺序排列后的下标) 为结尾的排列满足序列S的规则的数目

则有转移方程 

dp[i][j] = sum(dp[i-1][k])  (if S[i] == 'D' && k > j && k < i)
dp[i][j] = sum(dp[i-1][k])  (if S[i] == 'I' && k < j)

其意义是,我们用i这个数,替换了原本长度为i的数组(下标为0到i-1)中,下标为j的数，然后用j做新的结尾。
那么现在只要保证0到i-1下标的排序，最后一个数与原下标j对应的数的关系满足S序列的关系即可。

因为只看相对大小,所进行替换后,DP的意义不变。故当前dp[i-1][k]所表示的意义，与未替换前的dp[i-1][k]的意义相同。
所以，如果k大于j,那么在新的数组中下标为k的数也一定大于原本下标为j的数(因为新增了一个最大值)

同理，如果k小于j，那么在新的数组中下标为k的数也一定小于原本下标为j的数


********************************************/
class Solution {
public:
    int numPermsDISequence(string S) {
        int n = S.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        int mod = 1000000007;
        
        dp[0][0] = 1;
        
        for(int i = 1 ; i <= n ; ++i){
            for(int j = 0 ; j <= i ; ++j ){
                if(S[i-1] == 'D'){
                    for(int k = j ; k < i ; ++k){
                        dp[i][j] += dp[i-1][k];
                        dp[i][j] %= mod;
                    }
                }else{
                    for(int k = 0 ; k < j ; ++k){
                        dp[i][j] += dp[i-1][k];
                        dp[i][j] %= mod;
                    }
                } 
            }
        }
        
        int res = 0;
        
        for(int i = 0 ; i <= n ; ++i){
            res = (res + dp[n][i])%mod;    
        }
        
        return res;
    }
};
