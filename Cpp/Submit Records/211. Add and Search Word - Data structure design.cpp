/********************************************
作者:Alfeim
题目:添加与搜索单词-数据结构设计
时间消耗:296ms
解题思路:字典树(前缀树)
********************************************/
class TrieTree{
public:
    TrieTree():child(26,nullptr),is_word(false){
        
    }

vector<TrieTree*> child;
bool is_word;
};


class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieTree;    
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieTree* node = root;
        for(int i = 0 ;i < word.size();++i){
            if(!node->child[ word[i] - 'a'])
                node->child[ word[i] - 'a'] = new TrieTree;
            node = node->child[ word[i] - 'a'];
            if(i == word.size() - 1)
                node->is_word = true;
        }
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return Solve(root,word,0);
    }
    
    bool Solve(TrieTree* node,string word,int pos){
        if(pos == word.size()){
            return node->is_word;
        }
    
        if(word[pos] >= 'a' && word[pos] <= 'z'){
            if(node->child[ word[pos] - 'a'])
                return Solve(node->child[ word[pos] - 'a'],word,pos+1);
        }else if(word[pos] == '.'){
            for(int i = 0 ; i < 26 ; ++i){
                if( node->child[i] && Solve(node->child[i],word,pos+1))
                    return true;
            }
        }  
        
        return false;
    }    
    
TrieTree *root;
    
};
