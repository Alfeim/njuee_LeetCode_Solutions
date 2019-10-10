/********************************************
作者:Alfeim
题目:自除数
时间消耗:8ms
解题思路:..没啥好说的
********************************************/
class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        for(int i = left ; i <= right ; ++i){
            if(Solve(i)) res.push_back(i);
        }
        
        return res;
        
    }
    
    bool Solve(int number){
        
        int tmp = number;
        int bit = 0;
        
        while(tmp > 0){
            bit = tmp%10;
            if(bit == 0) return false;
            tmp /= 10;
            if((number % bit)) return false;
        }
        
        return true;
        
        
    }
};
