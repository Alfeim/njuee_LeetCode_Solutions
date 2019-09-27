/********************************************
作者:Alfeim
题目:单词子集
时间消耗:290ms
解题思路:维护定长数组,统计各字母出现次数即可
********************************************/
class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        vector<int> record(26,0);
        vector<string> res;
        for(auto i : B){
            
            vector<int> tmp(26,0);
            
            for(auto j : i){
                tmp[j - 'a']++;
            }
            
            for(int k = 0 ; k < 26 ; ++k){
                if(tmp[k] > record[k]) record[k] = tmp[k];
            }
            
        }
        
        
        bool flag;
        for(auto i : A){
            flag = true;
            vector<int> tmp(26,0);
            
            for(auto j : i){
                tmp[j - 'a']++;
            }
            
            for(int k = 0 ; k < 26 ; ++k){
                if(tmp[k] < record[k]){
                    flag = false;
                    break;
                }
            }
            
            if(flag) res.push_back(i);
        
        }
        
        return res;
    
    }
    

    
    
};
