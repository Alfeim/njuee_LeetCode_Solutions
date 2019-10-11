/********************************************
作者:Alfeim
题目:移动石子直到连续
时间消耗:28ms
解题思路:见 leetcode
https://leetcode-cn.com/problems/moving-stones-until-consecutive-ii/solution/jie-ti-si-lu-by-owenzzz/
********************************************/
class Solution {
public:
    vector<int> numMovesStonesII(vector<int>& stones) {
        sort(stones.begin(),stones.end());
        int n = stones.size();
        int maxres = stones[n-1] - stones[0] + 1 - n;
        maxres -= min(stones[n-1] - stones[n-2] - 1,stones[1] - stones[0] - 1);
        int minres= maxres;
        
        int i = 0;
        int j = 0;
        
        
        for(int i = 0 ; i < n ; ++i){
            
            while(j < n - 1 && stones[j+1] - stones[i] + 1 <= n) ++j;
            
            int tmp = n - (j - i + 1);
                
            if(j - i + 1 == n - 1 && stones[j] - stones[i] + 1 == n - 1 ) tmp = 2;
            
            minres = min(minres,tmp); 
            
        }
        
        return {minres,maxres};
        
        
    }
};
