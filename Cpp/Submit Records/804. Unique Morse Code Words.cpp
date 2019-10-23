/********************************************
作者:Alfeim
题目:唯一摩尔斯密码词
时间消耗:8ms
解题思路:哈希表
********************************************/
class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_set<string> record;
        vector<string> passwd{".-","-...","-.-.","-..",".","..-.","--.",
                              "....","..",".---","-.-",".-..","--","-.",
                              "---",".--.","--.-",".-.","...","-","..-",
                              "...-",".--","-..-","-.--","--.."};

        for(auto i : words){
            string curpasswd;
            for(auto j : i){
                curpasswd.append(passwd[j - 'a']);
            }
            record.insert(curpasswd);
        }

        return record.size();
    }

};
