/********************************************
作者:Alfeim
题目:检测大写字母
时间消耗:4ms
解题思路:

分三种情况

1、全大写

2、全小写

3、仅开头大写

每种情况都可以新建一个字符串.然后遍历原字串,进行对应操作。比如全大写，就把原字串的所有字符转大写后再对比和原字串是否相同

转换技巧利用了位运算的性质：

大写变小写、小写变大写 : 字符 ^= 32;

大写变小写、小写变小写 : 字符 |= 32;

小写变大写、大写变大写 : 字符 &= -33;
********************************************/
class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word.size() <= 1) return true;
        return  all_upper(word) || all_lower(word) || head_upper(word);
    }
    
    
    bool all_upper(string &word){
        string new_word;
        for(auto i : word) new_word += (i & -33);
        return new_word == word;
    }
    
    bool all_lower(string &word){
        string new_word;
        for(auto i : word) new_word += (i | 32);
        return new_word == word;
    }
    
    bool head_upper(string &word){
        string new_word;
        int n = word.size();
        int count = 0;
        for(auto i : word){
            if(count == 0) new_word += (i & -33);
            else new_word += (i | 32);
            count++;
        }
        return new_word == word;
    }
    
    
    
};
