/********************************************
作者:Alfeim
题目:求解方程
时间消耗:0ms
解题思路:细节题
********************************************/
class Solution {
public:
    string solveEquation(string equation) {
        int left_number = 0,right_number = 0;
        int left_x = 0,right_x = 0;
        
        int pos = 0;
        int n = equation.size();
        bool flag = true;
        while(pos < n && equation[pos] != '='){
            if(equation[pos] == '+' || equation[pos] == '-'){
                flag = equation[pos] == '+' ? true : false;
                pos++;
                continue;
            }else{
                string tmp;
                int tmp_number;
                while(pos < n && isdigit(equation[pos])) tmp += equation[pos++];
                tmp_number = tmp.size() > 0 ? stoi(tmp) : 1;
                if(equation[pos] == 'x'){
                    left_x += flag == true ? tmp_number : -tmp_number;
                    pos++;
                }else 
                    left_number += flag == true ? tmp_number : -tmp_number; 
            }   
        }  
        
        pos++;
        flag = true;
        while(pos < n){
            if(equation[pos] == '+' || equation[pos] == '-'){
                flag = equation[pos] == '+' ? true : false;
                pos++;
                continue;
            }else{
                string tmp;
                int tmp_number;
                while(pos < n  && isdigit(equation[pos])) tmp += equation[pos++];
                tmp_number = tmp.size() > 0 ? stoi(tmp) : 1;
                if(pos < n && equation[pos] == 'x'){
                    right_x += flag == true ? tmp_number : -tmp_number;
                    pos++;
                }else 
                    right_number += flag == true ? tmp_number : -tmp_number; 
            }
        }
        
        int res_x = left_x - right_x;
        int res_number = right_number - left_number;
        if(left_x == right_x && res_number == 0) return  "Infinite solutions";
        else if(left_x == right_x) return "No solution";

        return "x=" + to_string(res_number/res_x);
        

    }
};
