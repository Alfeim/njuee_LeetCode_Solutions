/********************************************
作者:Alfeim
题目:超级洗衣机
时间消耗:16ms
解题思路:分别查询每个位置需要往左边和往右边转移
多少衣服,取最大者即可
********************************************/
class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int n = machines.size();
        int res = INT_MAX;
        vector<int> sum(n+1,0);
        for(int i = 1 ; i <= n ; ++i){
            sum[i] += sum[i-1] + machines[i-1];
        }
        
        if(sum[n]%n != 0) 
            return -1;
        int avg = sum[n]/n;
        for(int i = 1 ; i <= n ; ++i){
            int sumLeft = sum[i-1];
            int sumRight = sum[n] - sum[i];
            int left_need = i == 1 ? 0 : avg * (i-1);
            int right_need = i == n ? 0 : avg *(n-i);
            if(left_need > 0 && right_need > 0){
                res = min(res,left_need + right_need);
            }else{
                res = min(res,max(abs(left_need),abs(right_need)));               
            }
        }
        
        return res;
        
        
    }
};
