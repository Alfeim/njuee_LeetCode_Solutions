/********************************************
作者:Alfeim
题目:前缀和后缀搜索
时间消耗:640ms
解题思路:字典树
********************************************/
class WordFilter {
public:
    struct prefixTree{
        prefixTree* childs[26]{nullptr};       
        
        bool isword;
        string word; 
        int pos;
        
        prefixTree():isword(false),word(""){};
        
    };
    
    
    WordFilter(vector<string>& words) {
        root = new prefixTree();
        int n = words.size();
        for(int i = 0 ; i < n ; ++i) Insert(words[i],i);
    }
    
    int f(string prefix, string suffix) {
        int res = -1,len = prefix.size(),i = 0;
        prefixTree *node = root;
        for(; i < len ; ++i){
            if(!node->childs[ prefix[i] - 'a' ]) break;
            node = node->childs[ prefix[i] - 'a' ];
        }
        
        if(i != len) return -1;
        Solve(node,suffix,res);
        return res;
    }
    
    void Insert(string &word,int pos){
        
        prefixTree *node = root;
        for(auto i : word){
            if(!node->childs[i-'a']) node->childs[i-'a'] = new prefixTree();
            node = node->childs[i-'a'];
        }
        
        node->isword = true;
        node->word = word;      
        node->pos = pos;
        
    }
    
    void Solve(prefixTree *node,string &suffix,int &res){
       
        if(node->isword){
            int m = node->word.size(),n = suffix.size(),i = 0;
            for(; m + i >= n && i < n ; ++i){
                if(node->word[m - n + i] != suffix[i] ) break;
            }
            
            if(i == n) res = max(res,node->pos);
        } 
        
        
        for(int i = 0 ; i < 26 ;++i){
            if(node->childs[i] != nullptr) Solve(node->childs[i],suffix,res);
        }
        
        
    }
    
    
    prefixTree *root;
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */
