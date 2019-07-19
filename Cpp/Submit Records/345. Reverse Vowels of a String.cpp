/********************************************
作者:Alfeim
题目:反转字符串中的元音字母
时间消耗:4ms
解题思路:双指针
********************************************/
class Solution {
public:
    string reverseVowels(string s) {
        int pos1 = 0,pos2 = s.size();
        unordered_set<char> record;
        record.insert('a');
        record.insert('e');
        record.insert('i');
        record.insert('o');
        record.insert('u');
        record.insert('A');
        record.insert('E');
        record.insert('I');
        record.insert('O');
        record.insert('U');
        while(pos1 < pos2){
            while(pos1 < pos2 && record.count(s[pos1]) == 0)
                pos1++;
            
            while(pos1 < pos2 && record.count(s[pos2]) == 0)
                pos2--;
            swap(s[pos1],s[pos2]);
            pos1++;
            pos2--;
        }
        
        return s;
        
    }
};
