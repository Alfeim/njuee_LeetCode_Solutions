/********************************************
作者:Alfeim
题目:根据字符串出现频率排序
时间消耗:16ms
解题思路:利用set自动排序,并自定义排序准则
********************************************/
class Solution {
public:
    struct cmp{
        
        bool operator()(const pair<int,char> &p1,const pair<int,char> &p2) const{
            return p1.first >= p2.first;
        } 
        
    };
    
    string frequencySort(string s) {
        unordered_map<char,int> counts;
        set<pair<int,char>,cmp> SET;
        string res;
        for(auto i : s) counts[i]++;
        for(auto j : counts) SET.insert(make_pair(j.second,j.first));
        for(auto l : SET) res += string(l.first,l.second);
        
        return res;
        
        
    }
};
