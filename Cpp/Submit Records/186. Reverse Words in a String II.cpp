/********************************************
作者:Alfeim
题目:翻转字符串里的单词2
时间消耗:76ms
解题思路:先逐个翻转,再翻转整个字符串即可
********************************************/
class Solution {
public:
    void reverseWords(vector<char>& s) {
        int n = s.size();
        int left = 0,right = -1;
        while(left < n && right < n){
            if(right < left) right = left;
            
            while(right < n && s[right] != ' ') right++;
            
            reverse(s,left,right);
            left = right+1;   
        }
        reverse(s,0,n);
        return;
    }
    
    void reverse(vector<char>& s,int left,int right){
        right--;
        while(left < right){
            swap(s[left],s[right]);
            left++;
            right--;
        }
        return;
    }
};
