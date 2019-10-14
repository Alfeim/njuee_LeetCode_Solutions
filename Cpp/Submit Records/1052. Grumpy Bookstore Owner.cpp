/********************************************
作者:Alfeim
题目:爱生气的书店老板
时间消耗:48ms
解题思路:滑动窗口
********************************************/
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int n = grumpy.size();
        int m = customers.size();
        
        if(m == 0 || n == 0) return 0;
        
        int res = 0;
        
        vector<int> person_sum(n,0);
        vector<int> Satisfy_sum(n,0);
        
       
        //统计人数和满意度前缀和,用于后续区间段的求解
        for(int i = 0 ; i < m ; ++i){
            person_sum[i] = ( (i == 0) ? 0 : person_sum[i-1] ) + customers[i];
            Satisfy_sum[i] = ( (i == 0) ? 0 : Satisfy_sum[i-1] ) +  ( (grumpy[i] == 1) ? 0 : customers[i] );
        }
    
        for(int i = m ; i < n ; ++i){
            person_sum[i] = person_sum[i-1];
            Satisfy_sum[i] = Satisfy_sum[i-1];
        }
        
        
        for(int i = X - 1 ; i < n ; ++i){
                
            int Satisfy_1 = ( i == X - 1 ) ? 0 : Satisfy_sum[i-X];
            int Satisfy_2 = person_sum[i] - ( (i == X - 1) ? 0 : person_sum[i-X] );
            int Satisfy_3 = Satisfy_sum[n-1] - Satisfy_sum[i];
            
            res = max(Satisfy_1 + Satisfy_2 + Satisfy_3,res);
        }
        
        return res;
    
    }
};
