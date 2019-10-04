/********************************************
作者:Alfeim
题目:设计哈希集合
时间消耗:128ms
解题思路:最直接的散列表的生成方式，即哈希函数为 键值%(大于最大值的最接近的一个素数)
********************************************/
class MyHashSet {
public:
    /** Initialize your data structure here. */
    MyHashSet():hash_container(1000007,0){
        
    }
    
    void add(int key) {
        hash_container[key % 1000007] = 1;
    }
    
    void remove(int key) {
        hash_container[key % 1000007] = 0;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return hash_container[key % 1000007] == 1;
    }
    
    vector<int> hash_container;
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
