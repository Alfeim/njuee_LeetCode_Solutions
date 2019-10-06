/********************************************
作者:Alfeim
题目:最低票价
时间消耗:8ms
解题思路:DP
********************************************/
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        
        if(n == 0 ) return 0;
        
        vector<int> dp(n,0);
        
        int MinOneDay = min(costs[0],min(costs[1],costs[2]));
        dp[0] = MinOneDay; 
        
        int cost1;
        int cost2;
        int cost3;
        
        for(int i = 1 ; i < n ; ++i){
            
            cost1 = INT_MAX;
            cost2 = INT_MAX;
            cost3 = INT_MAX;
            
            //第一种情况,单独买最后一天的票
            cost1 = dp[i-1] + MinOneDay;
            
            
            //第二种情况,前一次买的是7天的票，且能顺延到今天
            for(int j = i - 1 ; j >= 0 && days[j] > days[i] - 7  ; --j ) cost2 = min(cost2, costs[1] + ( ( j >= 1 ) ? dp[j-1] : 0 ));
            
            //第三种情况,前一次买的是30天的票，且能顺延到今天
            for(int j = i - 1 ; j >= 0 && days[j] > days[i] - 30 ; --j ) cost3 = min(cost3,costs[2] +  ( ( j >= 1 ) ? dp[j-1] : 0 ));
            
            dp[i] = min(cost1,min(cost2,cost3));
        }

        return dp[n-1];
     
    }
};
