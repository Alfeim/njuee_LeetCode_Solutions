/********************************************
作者:Alfeim
题目:字符串排列
时间消耗:12ms
解题思路:滑动窗口
********************************************/
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> record(26,0);
        vector<int> tmp(26,0);
        int m = s1.size(),n = s2.size();
        
        if(m > n) 
            return false;
        
        for(auto i : s1) 
            record[i - 'a']++;
        
        for(int left = 0 ,right = -1; left < n && right < n;){
            if(right < left) 
                right = left;
            
            tmp[s2[right] - 'a']++;
            if(tmp[s2[right] - 'a'] > record[s2[right] - 'a']){
                while(tmp[s2[right] - 'a'] > record[s2[right] - 'a']){
                    tmp[s2[left] - 'a']--;
                    left++;
                }
            }
            right++;
            if(right - left == m) 
                return true;
        }
        
        return false;
        
    }
};
