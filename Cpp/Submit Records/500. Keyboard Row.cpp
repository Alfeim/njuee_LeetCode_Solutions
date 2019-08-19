/********************************************
作者:Alfeim
题目:键盘行
时间消耗:0ms
解题思路:细节题
********************************************/
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<int> word(26,0);
        for(int i = 0 ; i < 26 ; ++i){
            if(i == 4 || i == 8 || i ==14 || i == 15 || i == 16 || i == 17 || i ==19 || i == 20 || i == 22 ||i == 24)
                word[i] = 1;
            else if(i ==  0 || i == 3 || i == 5 || i == 6 || i == 7 || i == 9 ||i == 10 || i == 11 || i == 18)
                word[i] = 2;
            else word[i] = 3;
        }
        
        vector<string> res;
        for(auto i : words){
            if(isOneLine(word,i)) res.push_back(i);
        }
        
        return res;
        
    }
    
    bool isOneLine(vector<int> &word,string &str){
        int line = word[(str[0] | 32) - 'a'];
        int n = str.size();
        for(int i = 1 ; i < n ; ++i){
            char low_word = str[i] | 32;
            if(word[low_word - 'a'] != line)
                return false;
        } 
        return true;
    }
    
    
};
