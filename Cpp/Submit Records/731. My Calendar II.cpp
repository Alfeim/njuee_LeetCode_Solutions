
/********************************************
作者:Alfeim
题目:我的日程安排表2
时间消耗:224ms
解题思路:
用一个数组记录出现过的时间段 用一个set结构存储已经重复过的时间段

比如当前时间段是{start,end}，首先查看当前时间段是否有与其他时间段有交集

如果有交集,再查看该交集是否与 存储了重复过的时间段 有交集,如果有就是三重交集,return false
********************************************/
class MyCalendarTwo {
public:
    vector<pair<int,int>> tmp;
    set<pair<int,int>> multi_records;
    MyCalendarTwo() {
        
    }
    
    bool has_multi(int start,int end){
        auto next = multi_records.lower_bound({start,end});
        auto before = next;before--;
        if(before->second > start || next->first < end)
            return true;
        
        multi_records.insert({start,end});
        return false;
    }
    
    bool book(int start, int end) {
        multi_records.clear();
        multi_records.insert({INT_MAX,INT_MAX});
        multi_records.insert({INT_MIN,INT_MIN});
        for(auto i : tmp){
            if(max(start,i.first) < min(end,i.second)){
                if(has_multi(max(start,i.first),min(end,i.second))) return false;   
            }
        }
        tmp.push_back({start,end});
        return true;
    } 
};



/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
