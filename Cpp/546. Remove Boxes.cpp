/********************************************
作者:Alfeim
题目:移除盒子
时间消耗:516ms
解题思路:DP

dp[i][j][k]表示i左边有连续紧邻个与nums[i]相同数字
情况下,消除nums[i,j]可以得到的最高分数;

其状态方程可以分为两种情况
1:消除nums[i]与其左边连续k个相同的数,再消除nums[i+1,j]
2:假设nums[i,j]中存在nums[m] == nums[i],则消除nums[i+1,m-1]
再消除nums[i]与nums[m,j];
********************************************/
class Solution {
public:
    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size();
        int dp[100][100][100] = {0}; 
        return Solve(boxes,0,n-1,0,dp);
    }
    
    int Solve(vector<int> &boxes,int i,int j,int k,int dp[100][100][100]){
        if(j < i) return 0;
        if(dp[i][j][k] > 0 ) return dp[i][j][k];
        int res = (1+k)*(1+k) + Solve(boxes,i+1,j,0,dp);
        for(int m = i + 1 ; m <= j ;++m){
            if(boxes[i] == boxes[m]){
                res = max(res,Solve(boxes,i+1,m-1,0,dp) + Solve(boxes,m,j,k+1,dp));
            }    
        }
        
        return dp[i][j][k] = res;
    }
    
    
};
