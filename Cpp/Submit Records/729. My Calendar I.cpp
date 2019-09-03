/********************************************
作者:Alfeim
题目:我的日程安排1
时间消耗:208ms
解题思路:利用set(map)自动排序
********************************************/

class MyCalendar {
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        if(record.empty()){
            record[start] = end;
            return true;
        }
        
        auto it = record.lower_bound(start);
        if(it == record.end()){
            if( (record.rbegin())->second <= start ){
                record[start] = end;
                return true;
            }
        }else{
            auto it_before = it;
            if(it == record.begin() && it->first >= end){
                record[start] = end;
                return true;
            }else{
                it_before--;
                if(it->first >= end && it_before->second <= start){
                    record[start] = end;
                    return true;
                }
            }
        }
  
        return false;
    }
    
    map<int,int> record;
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
 
 
//改进方法,先插入两个边界就不用考虑边界条件了
 class MyCalendar {
    set<pair<int,int>> sp;
public:

    //加入边界条件，之后可以不用判断边界
    MyCalendar() {
        sp.insert({INT_MAX,INT_MAX});
        sp.insert({INT_MIN,INT_MIN});
    }
    
    bool book(int start, int end) {
        auto next = sp.lower_bound({start,end});
        if(next->first<end) return false;
        if((--next)->second>start ) return false;
        sp.insert({start,end});
        return true;
    }
};

