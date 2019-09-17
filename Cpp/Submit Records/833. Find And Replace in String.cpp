/********************************************
作者:Alfeim
题目:字符串中的替换于查找
时间消耗:4ms
解题思路:哈希表
********************************************/
class Solution {
public:
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        int n = sources.size(),Lenth = S.size();;
        string res;
        unordered_map<int,vector<string>> replace; 
        
        for(int i = 0 ; i < n ; ++i){
            int pos = indexes[i];
            replace[pos].push_back(sources[i]);
            replace[pos].push_back(targets[i]);
        }
        
        for(int i = 0 ; i < Lenth ;){
            if(!replace.count(i)){
                res += S[i++];
                continue;
            }
            
            string src(replace[i][0]);
            string dst(replace[i][1]);
            
            int len = src.size(),j = 0;
                
            for(; j < len ; j++){
                if(S[i + j] != src[j] ) break;
            }
            
            if(j == len ) {
                res += dst;
                i += len;
            }else{
                res += S[i++];
            }
            
        }
        
        
        return res;
        
    }
};
