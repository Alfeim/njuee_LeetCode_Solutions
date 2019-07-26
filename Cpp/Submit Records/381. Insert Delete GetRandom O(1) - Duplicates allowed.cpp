/********************************************
作者:Alfeim
题目:O(1)时间插入、删除和获取随机元素
时间消耗:88ms
解题思路:利用哈希表
********************************************/
class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        int n = container.size();
        container.push_back(val);
        record[val].insert(n);
        return record[val].size() == 1;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if(record[val].empty())
            return false;
        
        int n = container.size();
        int cur_pos = *(record[val].begin());
        record[val].erase(cur_pos);
        
        if(cur_pos != n - 1){
            int last_elem = container.back();
            container[cur_pos] = last_elem;
            record[last_elem].erase(n-1);
            record[last_elem].insert(cur_pos);
        }
        
        container.pop_back();
        return true;
        
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return container[rand()%container.size()];   
    }
    
private:
    unordered_map<int,unordered_set<int>> record;
    vector<int> container;
};

