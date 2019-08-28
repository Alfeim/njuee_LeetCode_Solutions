/********************************************
作者:Alfeim
题目:实现一个魔法字典
时间消耗:8ms
解题思路:Trie树、哈希表
********************************************/
class MagicDictionary {
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
        record.clear();
        len_record.clear();
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for(auto i : dict) {
            len_record.insert(i.size());
            record.insert(i);
        }
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        int n = word.size();
        if(len_record.count(n) == 0) return false;
        
        for(int i = 0 ; i < n ; ++i){
            for(char c = 'a' ; c <= 'z' ; ++c){
                string tmp(word);
                tmp[i] = c;
                if(record.count(tmp) > 0 && tmp != word) return true;
            }
            
        }
        
        return false;
        
    }
    
private:
    unordered_set<string> record;
    unordered_set<int> len_record;
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dict);
 * bool param_2 = obj->search(word);
 */
