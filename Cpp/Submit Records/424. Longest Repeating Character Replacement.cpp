/********************************************
作者:Alfeim
题目:替换后的最长重复字符
时间消耗:4ms
解题思路:滑动窗口
********************************************/
class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0 , right = 0,maxcount = 0,res = 0;
        int n = s.size();
        vector<int> record(26,0);
        for(int right = 0 ; right < n ; ++right){
               maxcount = max(++record[s[right] - 'A'],maxcount);            
               if(right - left + 1 - maxcount > k){
                   record[s[left++] - 'A']--;
               }
                res = max(res,right - left + 1);
        }
        return res;
    }
};
