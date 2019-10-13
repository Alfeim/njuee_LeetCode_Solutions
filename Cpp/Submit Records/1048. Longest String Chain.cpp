/********************************************
作者:Alfeim
题目:最长字符串链
时间消耗:72ms
解题思路:DP、哈希表
********************************************/
class Solution {
public:
    struct cmp{
      bool operator()(const string &str1,const string &str2) const{
         return str1.size() < str2.size(); 
      };
    };
    
    int longestStrChain(vector<string>& words) {
        int n = words.size(),res = 0;
        
        sort(words.begin(),words.end(),cmp());
        
        unordered_map<string,int> record;
        
        for(auto i : words){
            
            int n = i.size();
            
            if(!record.count(i)) record[i] = 1;
            
            for(int j = 0 ; j < n ; ++j){
                string pre = i.substr(0,j) + i.substr(j+1);
                if(record.count(pre)){
                     record[i] = max(record[i] , record[pre] + 1);
                }      
            }
            
            res = max(res,record[i]);
            
        }
        
        return res;
        
        
    }
    
   
    
};
