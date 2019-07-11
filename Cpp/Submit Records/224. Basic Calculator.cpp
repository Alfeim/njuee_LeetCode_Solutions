/********************************************
作者:Alfeim
题目:搜索旋转排序数组
时间消耗:76ms
解题思路:通过中缀表达式构造后缀表达式，思路可见:
https://oi-wiki.org/basic/expression/
********************************************/
class Solution {
public:
    stack<long> res;
    vector<string> Suffix;
    stack<char> opera;
    int calculate(string s) {
      for(int i = 0 ; i < s.size();){
          if(s[i] == ' '){
              i++;
              continue;
          }
          else if(s[i] == '+' || s[i] == '-'){
              while(!opera.empty() && opera.top() != '('){
                  auto op = opera.top();
                  Suffix.push_back(string(1,op));
                  opera.pop();
              }
              opera.push(s[i++]);
              continue;
          }else if(s[i] == '('){
                opera.push(s[i++]);
                continue;
          }else if(s[i] == ')'){
              while(!opera.empty() && opera.top() != '('){
                  auto op = opera.top();
                  Suffix.push_back(string(1,op));
                  opera.pop();
              }
                 opera.pop();
                 i++;
                 continue;
          }
          
          string tmp;
          while( i < s.size() && s[i] >= '0' && s[i] <= '9')
              tmp += s[i++];
          Suffix.push_back(tmp);
      }
        
        while(!opera.empty()){
            auto op = opera.top();
            Suffix.push_back(string(1,op));
            opera.pop();
        }
    
        for(int i = 0 ; i < Suffix.size();++i){
            if(Suffix[i] == "+" || Suffix[i] == "-"){
                long number1 = 0,number2 = 0;
                if(!res.empty()){
                    number1 = res.top();
                    res.pop();
                }
                if(!res.empty()){
                    number2 = res.top();
                    res.pop();
                }
                long tmp = Suffix[i] == "+" ? number2 + number1 : number2 - number1;
                res.push(tmp); 
            }else{
                res.push(stoi(Suffix[i]));
            }
        }
         
        return res.top();
        
    }
 
};
