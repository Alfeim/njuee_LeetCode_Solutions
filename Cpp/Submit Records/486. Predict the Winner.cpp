/********************************************
作者:Alfeim
题目:预测赢家
时间消耗:4ms
解题思路:动态规划
********************************************/
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        //如果是偶数堆,那么必定为true,因为先手可以决定取到所有奇数位置或是偶数位置的数,而奇数位置的所有数之和与偶数位置的所有数之和必定存在大小关系或是相等
        if(n % 2 == 0) return true;
        
        vector<vector<pair<int,int>>> dp(n,vector<pair<int,int>>(n,make_pair(0,0)));   //元祖的第一个元素表示先手取得的最大和,第二个元素表示后手可以取得的最大和
        for(int i = 0 ; i < n; ++i) dp[i][i].first = nums[i],dp[i][i].second = 0;
        for(int len = 2 ; len <= n ; ++len){
            for(int begin = 0 ; begin < n - len + 1 ; ++begin){
                int end =  begin + len - 1;
                //如果先手选择最左
                int left = nums[begin] + dp[begin + 1][end].second;
                //如果先手选择最右
                int right = nums[end] + dp[begin][end-1].second;
                dp[begin][end].first =  left >= right ? left : right;
                dp[begin][end].second = left >= right ? dp[begin + 1][end].first : dp[begin][end-1].first;
            }
        }
        
        
        return dp[0][n-1].first >= dp[0][n-1].second; 
    }
};
