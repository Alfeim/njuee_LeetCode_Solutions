/********************************************
作者:Alfeim
题目:最短回文串
时间消耗:8ms
解题思路:思路不难,只需要确定以字符串开头为起始的最长回文串即可;
但是使用DP的方法会超时,这里需要使用Manacher算法(感受到了测试用
例的恶意)
********************************************/
class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size();
        int MaxP = 0;
        vector<int> d1(n);  //d1用来表示奇数长度回文串,每个位置对应的半径
        vector<int> d2(n);  //d2用来表示偶数长度回文串,每个位置对应的半径
        for(int i = 0 , l = 0 ,r = -1 ; i < n ; i++){
            int k = i > r ? 1 : min(r-i,d1[l + r - i]);
            while(i-k >= 0 && i + k < n && s[i-k] == s[i+k])
                k++;
            d1[i] = k--;
            if(i + k >= l){
                r = i + k;
                l = i - k;
            }
            if( l == 0)
                MaxP = max(MaxP,2*k + 1);
        }
         for(int i = 0 , l = 0 ,r = -1 ; i < n ; i++){
            int k = i > r ? 0 : min(r - i + 1,d2[l + r - i + 1]);
            while(i - k - 1 >= 0 && i + k < n && s[i-k-1] == s[i+k])
                k++;      
            d2[i] = k--;   
            if(i + k >= l){
                r = i + k;
                l = i - k - 1;
            }   
            if( l == 0)
                MaxP = max(MaxP,2*(k+1));
        } 
        string add = s.substr(MaxP);
        reverse(add.begin(),add.end());
        return add + s;
 
    }
 
};
