/********************************************
作者:Alfeim
题目:单词规律
时间消耗:8ms
解题思路:哈希表
********************************************/
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        //dict存储word和char的映射关系
        unordered_map<string,char> dict;
        vector<string> V;
        int n = pattern.size();
        string res;
        for(int i = 0 ; i < str.size();++i){
            if(str[i] == ' ')
                continue;
            string tmp;
            while(i < str.size() && str[i] != ' '){
                tmp += str[i++];
            }
            V.push_back(tmp);
        }
        if(V.size() != n)
            return false;
        for(int i = 0 ; i < n ;++i){
            
            if(dict.count(V[i]) == 0){
                for(auto it : dict){
                    if(it.second == pattern[i])
                        return false;
                }
                dict[V[i]] = pattern[i];
                res += pattern[i];
            }else{
                res += dict[V[i]];
            }
        } 
        return res == pattern;
    }
};
