/********************************************
作者:Alfeim
题目:棒球比赛
时间消耗:4ms
解题思路:...没啥好说的
********************************************/
class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> S;
        
        for(auto i : ops){
            int n = S.size();
            
            if(valid(i)){
                S.push_back(stoi(i));
            }else if(i == "+"){
                int sum = (n - 1 >= 0 ? S[n-1] : 0 )  + (n - 2 >= 0 ? S[n-2] : 0);
                S.push_back(sum);
            }else if(i == "D"){
                if(n > 0) S.push_back(2*S[n-1]);
            }else{
                if(!S.empty()) S.pop_back();
            }
        }
        
        int res = 0;

        for(auto i : S) res += i;
        
        return res;

    }
    
    
    bool valid(string &cur){
        if(cur != "D" && cur != "+" && cur != "C") return true;
        return false;
    }
    
    
};
