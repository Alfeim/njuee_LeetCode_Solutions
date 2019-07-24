/********************************************
作者:Alfeim
题目:将数据流变为多个不相交的区间
时间消耗:232ms
解题思路:利用map自动排序的性质
********************************************/
class SummaryRanges {
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        
    }
    
    void addNum(int val) {
        if(record.count(val) > 0)
            return;
        
        if(Area.count(val + 1) > 0){
            int tmp = Area[val + 1];
            Area.erase(val + 1);
            Area[val] = tmp;
        }else{
            Area[val] = val;
        }
        
        record.insert(val);
        
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> res;
        for(auto i : Area){
            if(res.empty()){
                res.push_back({i.first,i.second});
                continue;
            }
            int n = res.size() - 1;
            if(res[n][1] == i.first - 1 || res[n][1] >= i.first ){
                res[n][1] = i.second;
            }else{
                res.push_back({i.first,i.second});
            }
        }
        
        return res;
    }
    
private:
    map<int,int> Area;
    unordered_set<int> record;
};
