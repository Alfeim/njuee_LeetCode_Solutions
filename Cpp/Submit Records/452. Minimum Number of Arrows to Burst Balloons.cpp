/********************************************
作者:Alfeim
题目:用最少的箭引爆最多的气球
时间消耗:30ms
解题思路:排序、优先级队列
**************************************
class Solution {
public:
    struct cmp{
        bool operator()(const pair<int,int> &p1, const pair<int,int> &p2) const{
            if(p1.first < p2.first) 
                return false;
            else if(p1.first == p2.first) 
                return p1.second > p2.second;
            
            return true;
            
        }
        
    };
    
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.empty())
            return 0;
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> Q;
        for(auto i : points) Q.push(make_pair(i[0],i[1]));
        int begin = Q.top().first;
        int end = Q.top().second;
        Q.pop();
        int res = 1;
        while(!Q.empty()){
            auto cur = Q.top();
            if(cur.first > end || cur.second < begin){
                res++;
                begin = cur.first;
                end = cur.second;
            }else{
                begin = max(begin,cur.first);
                end = min(end,cur.second);
            }
            Q.pop();   
        }
        return res;
    }
};
