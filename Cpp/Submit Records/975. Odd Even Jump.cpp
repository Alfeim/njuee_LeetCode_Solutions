/********************************************
作者:Alfeim
题目:奇偶跳
时间消耗:172ms
解题思路:二分搜索 + dp
********************************************/
class Solution {
public:
    int oddEvenJumps(vector<int>& A) {
        int n = A.size();

        if(n <= 1) return n;

        vector<int> OddNext(n,n+1); //表示对于某个位置进行奇数跳跃而言的下一位置
        vector<int> EvenNext(n,n+1); //表示对于某个位置进行偶数跳跃而言的下一位置
        
        map<int,vector<int>> record;
        record[-1] = {n+1};
        record[100001] = {n+1};

        //利用二分搜索确定每个元素在奇数移动与偶数移动次数下的 “ 下一元素” 位置
        for(int i = n - 1 ; i >= 0 ; --i){
            auto oddnext = record.lower_bound(A[i]);
            auto evennext = oddnext;if(evennext->first > A[i]) evennext--;
            OddNext[i] = (oddnext->second).back();
            EvenNext[i] = (evennext->second).back();
            record[A[i]].push_back(i);
        }

        //dp[i][0]表示从i位置开始进行偶数移动能否到达终点
        //dp[i][1]表示从i位置开始进行奇数次移动能否到达终点

        vector<vector<bool>> dp(n,vector<bool>(2,false));   
        dp[n-1][0] = true; //结尾位置，跳0次(偶数)必然为真
        int res = 1;
        int oddnext;
        int evennext;
        for(int i = n - 2 ; i >= 0 ; i--){
            oddnext = OddNext[i];
            evennext = EvenNext[i];

            if( (oddnext == n - 1) || (oddnext < n - 1 && dp[oddnext][0] ) ){
                dp[i][1] = true;
            } 
            if( (evennext == n - 1) || (evennext < n - 1 && dp[evennext][1])){
                dp[i][0] = true;
            }
        }

        for(int i = 0 ; i < n - 1 ; ++i){
            int next = OddNext[i];
            if( next < n && dp[next][0] ) res++;
        }

        return res;
    }
};
