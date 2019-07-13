/********************************************
作者:Alfeim
题目:给表达式添加运算符
时间消耗:416ms
解题思路:回溯法，在过程中记录当前计算的值.在当前遍历三种符号,如果是+或-则更新之前的值
(利用一个值保存当前累乘的结果，如果过程中没有乘号则用1),如果是*将当前的值累乘到保存的值中
********************************************/
class Solution {
public:
    vector<vector<string>> res;
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        vector<string> tmp;
        Solve(target,0,1,num,tmp);
        for(auto i : res){
            string tmp;
            for(auto j : i)
                tmp += j;
            ans.push_back(tmp);
        }
        
        return ans;

    }
    
    void Solve(long long target,long long last,int sign,string num,vector<string> &tmp){
        if(num.empty()){
            target -= sign*last;
            if(target == 0)
                res.push_back(tmp);
            return;
        }
        
        for(int len = 1; len <= num.size();++len){
            if(num[0] == '0' && len > 1) 
                continue;
            if(!tmp.empty()){
                 
                 tmp.push_back("+");
                 tmp.push_back(num.substr(0,len));
                 Solve(target - sign*last,stoll(num.substr(0,len)),1,num.substr(len),tmp);
                 tmp.pop_back();
                 tmp.pop_back();
                
                 tmp.push_back("-");
                 tmp.push_back(num.substr(0,len));
                 Solve(target - sign*last,stoll(num.substr(0,len)),-1,num.substr(len),tmp);
                 tmp.pop_back();
                 tmp.pop_back();
                
                
                 tmp.push_back("*");
                 tmp.push_back(num.substr(0,len));
                 Solve(target,last*stoll(num.substr(0,len)),sign,num.substr(len),tmp);
                 tmp.pop_back();
                 tmp.pop_back();
            }else{
                tmp.push_back(num.substr(0,len));
                Solve(target,stoll(num.substr(0,len)),1,num.substr(len),tmp);
                tmp.pop_back();
            }           
        } 
    
    }
};
