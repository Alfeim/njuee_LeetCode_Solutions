/********************************************
作者:Alfeim
题目:赎金信
时间消耗:24ms
解题思路:哈希表
********************************************/
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> records(26,0);
        for(auto i :magazine)
            records[i - 'a']++;
        
        for(auto j : ransomNote){
            if(records[j - 'a'] <= 0)
                return false;
            records[j - 'a']--;
        }
        return true;
    }
};
