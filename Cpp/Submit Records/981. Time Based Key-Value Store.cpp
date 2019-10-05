/********************************************
作者:Alfeim
题目:基于时间的键值存储
时间消耗:600ms
解题思路:二维map
********************************************/
class TimeMap {
public:
    /** Initialize your data structure here. */
      
    TimeMap() {
        record.clear();
    }
    
    void set(string key, string value, int timestamp) {
        
        if(!record.count(key)){
            record[key][-1] = "";
            record[key][10000001] = "";
        }
        
        record[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        if(!record.count(key)) return "";
        
        auto it = record[key].lower_bound(timestamp);
        
        if(it->first == -1) return "";
        
        if(it->first == timestamp) return it->second;
        
        it--;
        
        return it->second; 
        
    }
    
private:
    unordered_map<string,map<int,string>> record;
    
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
