/********************************************
作者:Alfeim
题目:我的日程安排表3
时间消耗:284ms
解题思路:

把start、end看成游标，用map记录每个游标对应的区间数

当输入新的start、end时，让start对应的游标+1，end对应
的游标-1；

然后用一个变量记录当前遍历的游标和，K值也就是游标和中最大
的记录

********************************************/

class MyCalendarThree {
public:
    MyCalendarThree(){
        records.clear();
    }
    
    int book(int start, int end) {
        int res = 0,tmp = 0;
        records[start]++;
        records[end]--;
        for(auto i : records){
            tmp += i.second;
            res = max(tmp,res);
        }
        return res;
    }
private:
    map<int,int> records;

};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */
