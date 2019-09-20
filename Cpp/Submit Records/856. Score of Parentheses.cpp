/********************************************
作者:Alfeim
题目:括号的分数
时间消耗:0ms
解题思路:栈
********************************************/
class Solution {
public:
    stack<long> tmp;
    int scoreOfParentheses(string S) {
        //0表示左括号
        
        for(auto i : S){
            if( i == '(') {
                tmp.push(0);
                continue;
            }
            
            if(tmp.top() == 0){
                tmp.pop();
                tmp.push(1);
            }else{
                long res = 0;
                
                while(1){
                    res += tmp.top();
                    tmp.pop();
                    if(tmp.top() == 0) break;
                }    
                
                res *= 2;
                tmp.pop();
                tmp.push(res);
            }
            
        }
        
        long ans = 0;
        while(!tmp.empty()){
            ans += tmp.top();
            tmp.pop();
        }
        return ans; 
        
    }
};
