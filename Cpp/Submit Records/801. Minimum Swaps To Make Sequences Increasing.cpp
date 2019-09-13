/********************************************
作者:Alfeim
题目:使序列递增的最小交换次数
时间消耗:ms
解题思路:

因为要维持严格递增的性质,所以当我们遇到某处出现非严格递增时，其实有两种选择：
1.交换当前位置的两个元素
2.不交换当前位置的元素而是交换先前位置的元素
最终得到状态空间dp[i][j],i表示遍历到的下标,j表示是否交换最后一个元素,不交换时j == 0，交换时 j == 1；
********************************************/
class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        int n = A.size();
        if( n == 0) return 0;
        vector<vector<int>> dp(n,vector<int>(2,n));
        dp[0][0] = 0;
        dp[0][1] = 1;
        
        for(int i = 1 ; i < n ; ++i){
            dp[i][0] = min( (A[i] > A[i-1] && B[i] > B[i-1] ) ? dp[i-1][0] : n,   (A[i] > B[i-1] && B[i] > A[i-1]) ? dp[i-1][1] : n ); 
            dp[i][1] = min( (A[i] > B[i-1] && B[i] > A[i-1] ) ? 1 + dp[i-1][0] : n,   (A[i] > A[i-1] && B[i] > B[i-1]) ? 1 + dp[i-1][1] : n );
        }
        
        return min(dp[n-1][0],dp[n-1][1]);
    }
};
