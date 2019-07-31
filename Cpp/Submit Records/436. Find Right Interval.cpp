/********************************************
作者:Alfeim
题目:寻找右区间
时间消耗:160ms
解题思路:利用map自动排序
********************************************/
class Solution {
public:
    struct
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        map<int,int> record;
        vector<int> res;
        int n = intervals.size();
        for(int i = 0 ; i < n ; ++i)
            record[intervals[i][0]] = i;
        
        for(auto i : intervals){
            auto it = record.lower_bound(i[1]);
            int least_pos = INT_MAX;
            if(it != record.end()){
                least_pos = it->second;
            }else{
                least_pos = -1;
            }
            res.push_back(least_pos);
        }
        
        return res; 
    }
};
