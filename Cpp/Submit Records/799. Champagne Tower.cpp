/********************************************
作者:Alfeim
题目:香槟塔
时间消耗:16ms
解题思路:DP
********************************************/
class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        int n = pow(2,query_row - 1);
        vector<double> dp(100,0.0);
        
        if(poured <= 1){
            if(query_row == 0) return poured;
            return 0.0;
        }
        
        dp[0] = poured >= 1 ? poured - 1.0 : 0.0;

       
        
        for(int i = 1 ; i <= query_row ; ++i){
            int border = min(99,i);
            for(int j = border ; j >= 0  ; --j){ 
                if( j == border) dp[j] = dp[j-1] > 0.0 ? dp[j-1]*0.5 - 1.0 : -1.0;
                else if( j == 0) dp[j] = dp[j] > 0.0 ? dp[j]*0.5 - 1.0 : -1.0;
                else{   
                    double tmp = 0.0;
                    if(dp[j-1] > 0.0) tmp = tmp + dp[j-1]*0.5;
                    if(dp[j] > 0.0) tmp = tmp + dp[j]*0.5;
                    dp[j] = tmp - 1.0;
                }
            }
        }
        
        
        return dp[query_glass ] > 0.0 ? 1.0 : 1.0 + dp[query_glass];
        
    }
    
    
    
};
