/********************************************
作者:Alfeim
题目:分割数组的最大值
时间消耗:160ms
解题思路:动态规划
dp[k][j]表示以下标k为终点,分成j份情况下的最大值
我们发现状态dp[k][j]只取决于上一时刻的状态dp[l][j-1]和第一时刻的
状态dp[k][1]、dp[l][1]。所以可以采用倒序的方法遍历k,把二维DP变为1维
********************************************/

 
/*未优化版本*/
    int splitArray(vector<int>& nums, int m) {
        int len = nums.size();
        vector<vector<long>> dp(len + 1,vector<long>(m + 1,INT_MAX));
        dp[1][1] = nums[0];
        for(int i = 2 ; i <= len;++i)
            dp[i][1] = dp[i-1][1] + nums[i-1];
        
        for(int j = 2 ; j <= m ; ++j){
            for(int k = j ; k <= len ; ++k){
                long tmp = 0;
                for(int l = k - 1; l >= j - 1 ;--l){
                    tmp = max(dp[l][j-1],dp[k][1] - dp[l][1]);
                    dp[k][j] = min(dp[k][j],tmp);
                }
            }
        }
        return dp[len][m];
    }
    
    
/*优化后*/
    int splitArray(vector<int>& nums, int m) {
        int len = nums.size();
        vector<long> dp(len + 1,INT_MAX);
        vector<long> sum(len + 1,0);
        sum[1] = nums[0];
        dp[1] = nums[0];
        
        for(int i = 2 ; i <= len;++i){
            sum[i] = sum[i-1] + nums[i-1];
            dp[i] = sum[i];
        }
        
        for(int j = 2 ; j <= m ; ++j){
            for(int k = len ; k >= j ; --k){
                long tmp = 0;
                for(int l = k - 1; l >= j - 1 ;--l){
                    tmp = max(dp[l],sum[k]- sum[l]);
                    dp[k] = min(dp[k],tmp);
                }
            }
        }   
        
        return dp[len];
