/********************************************
作者:Alfeim
题目:键值映射
时间消耗:4ms
解题思路:Trie树、哈希表
********************************************/
class MapSum {
public:
    struct TrieTree{
        int val;
        int sumval;
        TrieTree *child[26]{nullptr};
        TrieTree():val(0),sumval(0){};
    };
    
    
    /** Initialize your data structure here. */
    MapSum() {
        root = new TrieTree();
        record.clear();
    }
    
    void insert(string key, int val) {
        TrieTree* cur = root;
        int n = key.size();
        for(int i = 0 ; i < n ; ++i){
            int pos = key[i] - 'a';  
            if(!cur->child[pos]) cur->child[pos] = new TrieTree();
            if(i != n - 1) (cur->child[pos])->sumval += val - record[key];
            cur = cur->child[pos];
        }
        record[key] = val;
        cur->val = val;
        return;
    }
    
    int sum(string prefix) {
        int n = prefix.size();
        TrieTree *cur = root;
        for(int i = 0 ; i < n ; ++i){
            int pos = prefix[i] - 'a';
            if(!cur->child[pos]) return 0;
            cur = cur->child[pos];
        }
        return cur->val + cur->sumval;
    }
    
    
private:
    TrieTree *root;
    unordered_map<string,int> record;
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
