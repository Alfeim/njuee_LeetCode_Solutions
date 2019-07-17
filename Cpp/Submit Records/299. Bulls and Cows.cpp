/********************************************
作者:Alfeim
题目:猜数字游戏
时间消耗:8ms
解题思路:哈希表
********************************************/
class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char,int> record;
        int Acount = 0;
        int Bcount = 0;
        for(auto i : secret)
            record[i]++;
        
        for(int j = 0 ; j < guess.size() && j < secret.size() ; ++j){
            if(guess[j] == secret[j]){
                Acount++;
                record[secret[j]]--;
            }
        }
        
        
         for(int k = 0 ; k < guess.size() && k < secret.size() ; ++k){
            if(guess[k] != secret[k]){
                if(record[guess[k]] > 0){
                    Bcount++;
                    record[guess[k]]--;
                }    
            }
        }
        
        string first = to_string(Acount) + 'A';
        string second = to_string(Bcount) + 'B';
        return first + second;
    }
};
