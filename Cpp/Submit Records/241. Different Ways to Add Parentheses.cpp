/********************************************
作者:Alfeim
题目:为运算表达式设计优先级
时间消耗:8ms
解题思路:分治法,遇到运算符就分别递归计算运算符左侧与运算符右侧,如果只剩下数字
则返回该数字.
********************************************/
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> res; 
        for(int i = 0 ; i < input.size();++i){
            auto word = input[i];
            if(word == '+' || word == '-' || word == '*'){
                auto r1 =  diffWaysToCompute(input.substr(0,i));
                auto r2 =  diffWaysToCompute(input.substr(i+1));
                for(auto j : r1){
                    for(auto k : r2){
                            if(word == '+')
                                res.push_back(j + k);
                            else if(word == '-')
                                res.push_back(j - k);
                            else
                                res.push_back(j * k);
                    }
                }
            }
        } 
         if(res.empty())
                res.push_back(stoi(input));  
         return res;
    }
};
