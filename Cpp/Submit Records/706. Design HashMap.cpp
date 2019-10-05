/********************************************
作者:Alfeim
题目:设计哈希映射
时间消耗:140ms
解题思路:哈希表的实现 数组 + 双向链表
********************************************/
class MyHashMap {
public:
    //自定义结构体
    struct node{
        int key;
        int val;
        node(int k,int v):key(k),val(v){};
    };
    
    /** Initialize your data structure here. */
    MyHashMap():HashMap(10007){
        
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int pos = hashfunc(key);
        
        for(auto &i : HashMap[pos]){
            if(i.key == key){
                i.val = value;
                return;
            }
        }
        
        node tmp(key,value);
        HashMap[pos].push_back(tmp);
        
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int pos = hashfunc(key);
        
        for(auto i : HashMap[pos]){
            if(i.key == key) return i.val;
        }
        
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int pos = hashfunc(key);
        
        auto it = HashMap[pos].begin();
        auto end = HashMap[pos].end();
        
        while(it != end){
            if(it->key == key) {
                HashMap[pos].erase(it);
                return;
            }
            it++;
        }
        
        return ;
        
    }
    
    //哈希函数
    int hashfunc(int key){
        return key % 10007;
    }
    
    
private:
    vector<list<node>> HashMap;
    
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
