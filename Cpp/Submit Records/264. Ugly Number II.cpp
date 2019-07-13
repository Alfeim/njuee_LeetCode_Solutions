/********************************************
作者:Alfeim
题目:丑数2
时间消耗:12ms
解题思路:用三个变量记录当前*2 *3和*5的位置
相似题目:263. 丑数
********************************************/
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>dp(n);
        dp[0] = 1;
        int multi1 = 0,multi2 = 0,multi3 = 0;
        for(int i = 1 ; i < n; ++i){
            int tmp1 = dp[multi1]*2;
            int tmp2 = dp[multi2]*3;
            int tmp3 = dp[multi3]*5;
            
            int Next = min(tmp1,min(tmp2,tmp3));
            
            if(Next == tmp1){
                multi1++;
            }
            if(Next == tmp2){
                multi2++;
            }
            if(Next == tmp3){
                multi3++;
            }
            dp[i] = Next;
        }
        return dp[n-1];
        
    }
};
