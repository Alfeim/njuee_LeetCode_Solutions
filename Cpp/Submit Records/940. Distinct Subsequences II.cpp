/********************************************
作者:Alfeim
题目:不同的子序列2
时间消耗:8ms
解题思路:DP
如果以dp[i]表示以S[i]为结尾的子序列数量,其转移方程为dp[i] = dp[i] + dp[j] ,其中j为i之前的某个下标，这个转移关系很容易看出.

但是，由于存在重复问题,所以如果在j之前还有和j下标对应字母相同的位置(假设为k)，则应当忽略该位置，因为以j下标为结尾的子序列一定包含了所有以k希表为结尾的子序列的情况（重要）

那么如果我们用一个数组word_count保存上一状态存储的以某个字母为结尾的子序列数目，实际上dp[j]和word_count[S[j]-'a']的意义相同！

那么现在，可以看出,实际上我们不再需要关心下标i是什么，只需要关系结尾字母是什么即可！

所以可以优化空间消耗为O(1),时间消耗为O(N)了！(与下标无关，只与字母有关，一共只有26个小写字母)
********************************************/
class Solution {
public:
    int distinctSubseqII(string S) {
        int n = S.size();
        if(n <= 1) return n;
        long mod = 1000000007;
        vector<long> word_count(26,0);
   
        for(int i = 0 ; i < n ; ++i){
            int tmp = 1;
            for(int j = 0 ; j < 26 ; ++j){
                tmp += word_count[j];
                tmp %= mod;
            }
            word_count[S[i] - 'a'] = tmp;
        }

        long res = 0;
        for(int i = 0 ; i < 26 ; ++i){
            res += word_count[i];
            res %= mod;
        }

        return res;

    }
};
