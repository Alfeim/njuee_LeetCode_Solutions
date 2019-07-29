/********************************************
作者:Alfeim
题目:青蛙过河
时间消耗:256ms
解题思路:动态规划
********************************************/
class Solution {
public:
    unordered_map<int,int> record;
    bool canCross(vector<int>& stones) {
        int m = stones.size();
        if(m <= 1) return true;
        for(int i = 0 ; i < m ; ++i) record[stones[i]] = i;
        
        vector<vector<bool>> dp(m,vector<bool>(m,false));
        dp[0][1] = stones[1] - stones[0] == 1;
        
        for(int i = 0 ; i < m ; ++i){
            for(int j = i + 1 ; j < m ; ++j){
                if(dp[i][j]){
                    int step = stones[j] - stones[i];
                    for(int k = -1 ; k <= 1; ++k){
                        int dst = stones[j] + step + k;
                        if(record.count(dst) > 0){
                            if(dst == stones.back()) return true;
                            dp[j][record[dst]] = true; 
                        }
                    } 
                }  
            }
        }
        
        return false;
    }
    
    
    
};
