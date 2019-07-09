/********************************************
作者:Alfeim
题目:同构字符串
时间消耗:12ms
解题思路:散列表
********************************************/
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> dict;
        unordered_set<char> visited;
        for(int i = 0 ; i < t.size() && i < s.size();++i){
            if(dict.count(s[i]) == 0 && visited.count(t[i]) == 0){
                visited.insert(t[i]);
                dict[s[i]] = t[i];
                s[i] = t[i];
            }else if(dict.count(s[i]) > 0){
                s[i] = dict[s[i]];
            }
        }  
        return s == t;
    }
};
