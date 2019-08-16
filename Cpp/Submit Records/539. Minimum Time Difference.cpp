/********************************************
作者:Alfeim
题目:最小时间差
时间消耗:32ms
解题思路:利用set自动排序
********************************************/
class Solution {
public:
    multiset<int> records;
    int findMinDifference(vector<string>& timePoints) {
        int res = INT_MAX;
        for(auto i : timePoints){
            int curtime = to_int_time(i);
            if(records.count(curtime) > 0) 
                return 0;
            records.insert(curtime);
        }
        
        auto it1 = records.begin();
        auto it2 = records.begin();it2++;
        while(it2 != records.end()){
            int diff = *it2 - *it1;
            res = min(res,diff);
            it1++;
            it2++;
        }
        int tmp = *it1 - *(records.begin());
        res = min(res,1440 - tmp);
        
        return res;
        
        
    }
    
    int to_int_time(string &time){
        int n = time.size();
        int i = 0;
        for(; i < n && time[i] != ':'; ++i);
        return stoi(time.substr(0,i))*60 + stoi(time.substr(i+1));
    }
    
};
