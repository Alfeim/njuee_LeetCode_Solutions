/********************************************
作者:Alfeim
题目:通过删除字母匹配到字典里最长单词
时间消耗:88ms
解题思路:双指针、排序
********************************************/

class Solution {
public:
      static bool cmp(string &a , string &b){
            if(a.size() > b.size())
                return true;
            else if( a.size() == b.size() ){
                int n = a.size();
                int i = 0;
                for(; i < n ; ++i){
                    if(a[i] != b[i]) break;
                }
                return i == n || a[i] < b[i];
            }
            return false;
        }

    string findLongestWord(string s, vector<string>& d) {
        sort(d.begin(),d.end(),cmp);
    
        for(auto i : d){
            if(isSubseq(i,s)) return i;
        }
        
        return "";
    }
    
    bool isSubseq(string &a,string &b){
        int i = 0 , j = 0, m = a.size(), n = b.size();
        while(i < m && j < n){
            if(a[i] == b[j]) i++;
            j++;
        }
        return i == m;
    }
    

    
   
};
