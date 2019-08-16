/********************************************
作者:Alfeim
题目:自由之路
时间消耗:552ms
解题思路:DPi
dp[i][j]表示从ring[j]起始要拼出key[i]及其之后
的字符串所需要的最小步数
********************************************/
class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int m = ring.size();
        int n = key.size();
        vector<vector<int>> dp(m,vector<int>(n+1,0));
        
        for(int i = n - 1 ; i >= 0 ; --i){
            for(int j = 0 ; j < m ; ++j){
                dp[j][i] = INT_MAX;
                for(int k = 0 ; k < m ; ++k){
                    if(ring[k] == key[i]){
                        int diff1 = abs(j-k);
                        int diff2 = m - diff1;
                        dp[j][i] = min(dp[j][i],min(diff1,diff2) + dp[k][i+1]);
                    }   
                }
            }
        }
        return dp[0][0] + n;
    }
};
