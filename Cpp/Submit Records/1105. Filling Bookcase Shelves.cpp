/********************************************
作者:Alfeim
题目:填充书架
时间消耗:8ms
解题思路:DP
********************************************/
class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
        int n = books.size();
        
        //dp[i]表示到放第i本书为止可能的最小高度
        vector<int> dp(n+1,10000001);
        vector<int> Wsum(n+1,0);
        
        for(int i = 0 ; i < n ; ++i) Wsum[i+1] = Wsum[i] + books[i][0];
        
        dp[0] = 0;
        
        for(int i = 1 ; i <= n ; ++i){
            int maxHeight = 0;
            //要找出最小高度,只需要反向变量,看哪些书和最后一本书在同一层。故有转移方程dp[i] = dp[j-1] + maxHeight(books[j-1] ~ books[i-1])
            for(int j = i ; j > 0 && Wsum[i] - Wsum[j-1] <= shelf_width ; --j){
                maxHeight = max(maxHeight,books[j-1][1]);
                dp[i] = min(dp[i],dp[j-1] + maxHeight);
            }    
        }

        return dp[n];
        
        
    }
};
