/********************************************
作者:Alfeim
题目:迷你语法分析器
时间消耗:4ms
解题思路:栈;同时用一个数组存储"["对应的位置
********************************************/
class Solution {
public:
    stack<NestedInteger> res;
    vector<int> pos;
    stack<string> tmp;
    NestedInteger deserialize(string s) {
        int n = s.size();
        for(int i = 0 ; i < n;++i){
             if(s[i] == ',')
                 continue;
             else if(s[i] == '['){
                 tmp.push("[");
                 pos.push_back(res.size());
                 continue;
             }else if(s[i] == '-' || (s[i] >= '0' && s[i] <= '9') ){
                 string number;
                 while(1){
                     number += s[i]; 
                     if(i == n - 1) break;
                     if(s[i + 1] >= '0' && s[i + 1] <= '9') i++;
                     else break;
                 }
                 res.push(NestedInteger(stoi(number)));
             }else{
                 stack<NestedInteger> newList;
                 NestedInteger updated;
                 auto cur = pos.back();
                 pos.pop_back();
                 while(res.size() > cur){
                    newList.push(res.top());
                    res.pop();
                 }
                 
                 while(!newList.empty()){
                     updated.add(newList.top());
                     newList.pop();
                 }
                 
                 res.push(updated);
             }
        }
        
        return res.top();
    }
    
    
    
    
    
};
