/********************************************
作者:Alfeim
题目:最低加油次数
时间消耗:12ms
解题思路:
1.Dp,Dp[i]表示加油i次可以走的最远路程
2.优先级队列
********************************************/
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int,vector<int>,less<int>> Q;
        
        int oil = startFuel;
        int cur_pos = 0;
        int last_pos = 0;
        int res = 0;
        
        stations.push_back({target,0});
        
        
        for(auto i : stations){
            
            cur_pos = i[0];
            oil -= (cur_pos - last_pos);
            
            while(!Q.empty() && oil < 0){
                oil += Q.top();
                Q.pop();
                res++;
            }
            
            if(oil < 0) return -1;
            
            last_pos = cur_pos;
            
            Q.push(i[1]);
            
        }
        
        return res;
        
        
    }
};
