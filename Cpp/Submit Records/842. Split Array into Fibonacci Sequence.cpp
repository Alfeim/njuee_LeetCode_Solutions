/********************************************
作者:Alfeim
题目:将数组拆分成斐波那契数列
时间消耗:8ms
解题思路:DFS
********************************************/
class Solution {
public:
    vector<int> splitIntoFibonacci(string S) {
        vector<int> res;
        Solve(0,res,S);
        return res;
    }
    
    bool Solve(int pos,vector<int>& tmp,string &S){
        int n = S.size();
        
        if(pos == n){
            return tmp.size() >= 3;
        }
        
        long number = 0;
        
        for(int i = pos ; i < n ; ++i){
            number = number * 10 + (S[i] - '0');
            if(number > INT_MAX) break;
            
            int len = tmp.size();
            if(len <= 1){
                tmp.push_back(number);
                if(Solve(i+1,tmp,S)) return true;
                tmp.pop_back();
            }else{
                int number1 = tmp[len-1],number2 = tmp[len-2];
                long sum = (long)number1 + (long)number2;
                
                if( sum < number) return false;
                
                if(sum == number){
                    tmp.push_back(number);
                    if(Solve(i+1,tmp,S)) return true;
                    tmp.pop_back();
                }
            }
            
            if(S[pos] == '0') break;
        }
        return false;
    }
    
};
