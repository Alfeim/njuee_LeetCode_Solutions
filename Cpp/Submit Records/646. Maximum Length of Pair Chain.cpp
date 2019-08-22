/********************************************
作者:Alfeim
题目:最长数对链
时间消耗:302ms
解题思路:DP、贪心
********************************************/
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        if(pairs.empty()) return 0;
        int n = pairs.size();
        int res = INT_MIN;
        sort(pairs.begin(),pairs.end(),[](vector<int> &v1,vector<int> &v2){return v1[1] < v2[1];});
        vector<int> dp(n,1);
        for(int i = 0 ; i < n; ++i){
            for(int j = i - 1; j >= 0 ; --j){
                if(pairs[i][0] > pairs[j][1]) dp[i] = max(dp[i],1 + dp[j]);   
            }
            res = max(dp[i],res);
        }
        return res;
    }
};
