/********************************************
作者:Alfeim
题目:查找和替换模式
时间消耗:8ms
解题思路:哈希表
********************************************/

class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        int n = pattern.size();
        vector<string> res;
        int pos;
        for(auto i : words){
            unordered_map<char,char> M;
            unordered_map<char,char> rM;
            
            string tmp(i);
            pos = 0;         
            
            if(i.size() != n) continue;
            
            for(;pos < n ; ++pos){
                if(!M.count(tmp[pos]) && !rM.count(pattern[pos])){
                    M[tmp[pos]] = pattern[pos];
                    rM[pattern[pos]] = tmp[pos];
                }else{
                    if(!M.count(tmp[pos]) && rM.count(pattern[pos])) break;
                    if( M.count(tmp[pos]) && !rM.count(pattern[pos])) break;
                    if(M[tmp[pos]] != pattern[pos]) break;   
                }
                
                tmp[pos] = pattern[pos]; 
            }
            
            if(pos == n) res.push_back(i);
        }
        
        
        return res;
    }
};
