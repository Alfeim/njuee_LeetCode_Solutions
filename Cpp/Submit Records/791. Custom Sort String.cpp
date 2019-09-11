/********************************************
作者:Alfeim
题目:自定义字符串排序
时间消耗:0ms
解题思路:自定义排序准则
********************************************/
class Solution {
public:
    string customSortString(string S, string T) {
        vector<int> order(26,-1);
        int n = S.size();
        string res1;
        string res2;
        for(int i = 0 ; i < n ; ++i){
           order[S[i] -'a'] = i;  
        } 
        
        for(auto i : T){
            if(order[i - 'a'] == -1) res2 += i;
            else res1 += i;
        }
        
        sort(res1.begin(),res1.end(),[&order](char c1,char c2){return order[c1 - 'a'] < order[c2 - 'a'];});
        return res1 + res2;
        
    }
};
