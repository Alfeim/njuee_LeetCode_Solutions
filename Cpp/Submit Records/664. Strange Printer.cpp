/********************************************
作者:Alfeim
题目:奇怪的打印机
时间消耗:40ms
解题思路:DP
用dp[i][j]表示打印下标i到下标j所需要的最少步数

当我们打印了一个新字符时,首先如果该字符和已打印字符的末尾相同,那么所需步骤和打印先前字符的步骤相同
(很好理解,我们只需要在末尾连续打印就行了)

如果该字符与末尾字符不同,那么我们向前寻找是否有与当前字符相同的字符。直观些举个例子,比如先前字符是
aabac,假设我们还需要打印一个a,我们发现先前字符在三个位置上都有a；所以可以这样尝试:先打印aabaaa,然
后替换为aabaca;也可以先打印aaaaaa,然后替换成aabaca;对应的转移方程就是:

dp[i][end] = min(dp[i][end],dp[i][j] + dp[j+1][end-1]);

其中j表示先前字符串中与当前字符相同的字符所在的位置.那么dp[i][j]也就是打印先前字符并且尾部再连续打
end - j 个当前字符所需的步数。而dp[j+1][end-1]也就是替换尾部那些字串所需要的步数！


********************************************/
class Solution {
public:
    int strangePrinter(string s) {
        int n = s.size();
        if(n <= 1) return n;  
        vector<vector<int>> dp(n,vector<int>(n,n+1));
        
        for(int i = 0; i < n ; ++i) {
            dp[i][i] = 1;
            if(i < n - 1) dp[i][i+1] = s[i] == s[i + 1] ? 1 : 2;
        }
        
        for(int len = 3 ; len <= n ; ++len){
            for(int i = 0 ; i < n - len + 1 ; ++i){
                int end = i + len - 1;
                if(s[end] == s[end-1]) 
                    dp[i][end] = dp[i][end-1];
                else{
                    dp[i][end] = dp[i][end-1] + 1;
                    for(int j = end - 1 ; j >= i ; j--){
                        if(s[j] == s[end]){
                            dp[i][end] = min(dp[i][j] + dp[j+1][end-1],dp[i][end]);
                        }
                    }
                }
            }
        }
        
        return dp[0][n-1];
    }
};
