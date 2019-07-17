/********************************************
作者:Alfeim
题目:累加数
时间消耗:0ms
解题思路:回溯,用字符串计算代替=号防止溢出
********************************************/
class Solution {
public:
    bool isAdditiveNumber(string num) {
        vector<string> tmp;
        return Solve(0,num,tmp);
    }
    
    bool Solve(int begin,string num,vector<string> &tmp){
         if(begin >= num.size()){
             return tmp.size() > 2;
         }
         if(num[begin] == '0'){
             if(tmp.size() < 2 || equals(tmp,"0")){
                 tmp.push_back("0");
                 if(Solve(begin+1,num,tmp))
                     return true;
                 tmp.pop_back();
             }
         }
         else{
            for(int i = begin ; i < num.size();++i){
                string number(num.substr(begin,i-begin+1));
                if(tmp.size() < 2 || equals(tmp,number)){
                        tmp.push_back(number);
                        if(Solve(i+1,num,tmp))
                            return true;
                        tmp.pop_back();
                   } 
                }
            }
        
        return false;
    }
    
    bool equals(vector<string> &tmp,string target){
        int n = tmp.size();
        string first(tmp[n-2]);
        string second(tmp[n-1]);  
        if(first.size() > second.size())
            swap(first,second);
        
        int carry = 0;
        int fs = first.size()-1;
        int ss = second.size()-1;
        int ts = target.size()-1;
        
        if(ts < ss || ts < fs || ts - ss >= 2)
            return false;
        
        for(int i = 0 ; i < second.size();++i){
            int a1 = second[ss - i] - '0';
            int a2 = i >= first.size() ? 0 : first[fs - i] - '0';
            int curr = (a1 + a2 + carry) % 10;
            carry = (a1 + a2 + carry) / 10;
            if(curr != target[ts-i] - '0')
                return false; 
        }
      
        return true;
    }
    
};
