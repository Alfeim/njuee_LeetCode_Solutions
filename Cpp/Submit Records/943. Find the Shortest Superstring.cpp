/********************************************
作者:Alfeim
题目:最短超级串
时间消耗:120ms
解题思路:动态规划

dp[i][j]表示以i下标的字符串为开头，状态为j的字符串组合的最短长度

所谓状态指的是，当前的字符串组合包含了哪些下标位置的字符串。我们用一个32位的整型表示(题意最多只有12个字符串)
如果当前状态的某一位被置1，说明该位置对应的偏移量下标字符串存在于当前的字符串组合中。

按照状态中"1"的个数我们开始从小到大遍历(表示字符串组合由多少个字符串组成)即可

********************************************/
class Solution {
public:
    string shortestSuperstring(vector<string>& A) {
        int n = A.size();
        
        if(n == 0) return "";

        if(n == 1) return A[0];

        int border = pow(2,n); //border表示最大的状态，依据题意，实际上最多只可能有2^12 = 4096个状态,所以最大状态实际上就是4095(二进制表示下)

        vector<vector<int>> pLen(n,vector<int>(n,0)); //pLen[i][j]表示下标i的字符串的后缀 是 下标j的字符串前缀 的最大长度
        vector<vector<int>> BitNumber(n+1);           //BitNumber表示当前的字符串中已经包含了A中的几个字符串，也就等价于1的位数
        vector<int> wLen(n,0);                        //Wlen记录对应下标的字符串长度，减少调用size()方法带来的时间消耗

        for(int i = 0 ; i < n ; ++i){
            wLen[i] = A[i].size();
            for(int j = i + 1 ; j < n ; ++j){
                pLen[i][j] = posfixLen(A[i],A[j]);
                pLen[j][i] = posfixLen(A[j],A[i]);
            }
        }


        //遍历所有状态,把这些状态按照1的位数放到不同记录中
        for(int number = 0 ; number < border ; ++number) BitNumber[bits(number)].push_back(number);
       
        //dp记录以i下标对应的字母为开头,状态为j的最小长度
        vector<vector<int>> dp(n,vector<int>(border,300));

        //初始化，如果只有一个字符串，那么state就是1 左移 该字符串对应的下标的偏移量，且长度就是该字符串的长度
        for(int i = 0 ; i < n ; ++i) dp[i][1 << i] = wLen[i];

        //next记录以i下标为开头，状态为j时候长度最小时，下一个字母的下标
        vector<vector<int>> next(n,vector<int>(border,-1));
        int nextstate = 0;
        int tmpLen = 0;

        //从包含2个字符串的情况开始遍历
        for(int slen = 2 ; slen <= n ; ++slen){
            for(int i = 0 ; i < n ; ++i){
                for(int j = 0 ; j < n ; ++j){
                    if( i == j ) continue;
                    for(auto state : BitNumber[slen]){
                        if( (state >> i) & 1 == 0 ) continue;
                        if( (state >> j) & 1 == 0 ) continue;
                        nextstate = GetNextState(state,i);
                        tmpLen = wLen[i] + dp[j][nextstate] - pLen[i][j];                 
                        if(tmpLen < dp[i][state]){
                            next[i][state] = j;
                            dp[i][state] = tmpLen;
                        }
                    }
                }
            }
        }


        //输出结果
        return GetResult(A,pLen,next,dp,border-1);

    }

    string GetResult(vector<string>& A,vector<vector<int>> pLen,vector<vector<int>> &next,vector<vector<int>> &dp,int curstate){
        int n = A.size();
        int curpos = 0;

        for(int i = 0,tmp = 300; i < n ; ++i){
            if(dp[i][curstate] < tmp){
                curpos = i;
                tmp = dp[i][curstate];
            }
        }

        string res(A[curpos]); 
        int nextstate = 0;
        int nextpos = 0;
        for(int i = 1 ; i < n ; ++i){
            nextstate = GetNextState(curstate,curpos);
            nextpos = next[curpos][curstate];
            res.append(A[nextpos].substr(pLen[curpos][nextpos]));
            curstate = nextstate;
            curpos = nextpos;
        }
        return res;
    }


    int GetNextState(int curstate,int curpos){
        return (( curstate >> (curpos + 1) ) << (curpos + 1) ) | (curstate & ((1 << curpos) -1 ));
    }

    int bits(int number){
        int bit_count = 0;
        while(number > 0){
            bit_count++;
            number &= (number - 1);
        }
        return bit_count;
    }

    int posfixLen(string &str1,string &str2){
        int n = str1.size();
        int m = str2.size();
        int maxLen = 0;

        for(int i = 1 ; i < m && i < n ; ++i){
            if(str1.substr(n-i) == str2.substr(0,i)) maxLen = i;
        }

        return maxLen;
    }
};
