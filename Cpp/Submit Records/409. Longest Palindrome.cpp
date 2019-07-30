/********************************************
作者:Alfeim
题目:最长回文串
时间消耗:12ms
解题思路:哈希表记录每个单词的出现次数
********************************************/
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> counts;
        int n  =  s.size();
        int res = 0;
        for(auto i : s){
            if(counts[i]%2 == 1) res++;
            counts[i]++;
        }
        
        return 2*res + 1 > n ? n : 2*res + 1;
    }
};
