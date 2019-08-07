/********************************************
作者:Alfeim
题目:连接词
时间消耗:320ms
解题思路:dfs
********************************************/
class Solution {
public:
    unordered_set<string> record;
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> res;
        for(auto i : words) record.insert(i);
        for(auto i : words){
            if(dfs(i,0,i.size(),0))
                res.push_back(i);
        }
        
        return res;
        
    }
    
    bool dfs(string &word,int begin,int len,int cnt){
        if(begin >= len)
            return cnt > 1;
        
         for(int end = begin ; end < len ; ++end){
             if(record.count(word.substr(begin,end - begin + 1)) > 0 ){
                    if(dfs(word,end + 1,len,cnt+1))
                        return true;
             }
         }
        
        return false;
        
    }
    
};
