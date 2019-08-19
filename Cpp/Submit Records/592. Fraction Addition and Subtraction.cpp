/********************************************
作者:Alfeim
题目:分数加减运算
时间消耗:0ms
解题思路:细节题
********************************************/
class Solution {
public:
    multimap<int,int> numbers;
    string fractionAddition(string expression) {
        long fz = 0 ;
        long fm = 0;
        int n = expression.size();
        for(int i = 0 ; i < n ;){
            if(isdigit(expression[i]) || expression[i] == '+' || expression[i] == '-'){
                string tmp1;
                string tmp2;
                while(expression[i] != '/'){
                    tmp1 += expression[i];
                    i++;
                }i++;
                while(i < n && expression[i] != '+' && expression[i] != '-'){
                    tmp2 += expression[i];
                    i++;
                }
                numbers.insert(make_pair(stoi(tmp2),stoi(tmp1)));
            }
        }
        
        for(auto i : numbers){
            if(fm == 0){
                fz = i.second;
                fm = i.first;
            }else{
                fz = fz * i.first +  i.second * fm;
                fm *= i.first;
            }
        }
        if(fz == 0) return "0/1";
        int GCD = gcd(abs(fz),abs(fm));
        return to_string(fz/GCD) + "/" + to_string(fm/GCD);
        
    }
    
    int gcd(int x,int y){
        while(y){
            int t = x % y;
            x = y;
            y = t;
        }
        return x;
    }
    
    
    
};
