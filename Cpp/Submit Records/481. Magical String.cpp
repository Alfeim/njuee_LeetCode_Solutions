/********************************************
作者:Alfeim
题目:神奇字符串
时间消耗:16ms
解题思路:记忆化
********************************************/
class Solution {
public:
    int magicalString(int n) { 
        if(n == 0)
            return 0;
        
        if(n <= 3)
            return 1;
        
        int res = 1;
        vector<int> dp(n+1,0);
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 2;
        int last = 4;
        for(int i = 3 ; i <= n ; ++i){
            if(dp[i] == 2){
                if(last <= n){
                    dp[last] = dp[last-1] == 1 ? 2 : 1;
                    if(last <= n - 1)
                        dp[last + 1] = dp[last];
                    last += 2;
                }
            }else if(dp[i] == 1){
                res++;
                if(last <= n){
                    dp[last]= dp[last-1] == 1 ? 2 : 1;
                    last += 1;
                }
            }  
        }
        return res;
    }
};
