/********************************************
作者:Alfeim
题目:子数组最小之和
时间消耗:148ms
解题思路:栈
********************************************/
class Solution {
public:
    struct element{
        int val;
        int pos;
        int sum;
        element(int _val,int _pos,int _sum):val(_val),pos(_pos),sum(_sum){};
    };
    
    int sumSubarrayMins(vector<int>& A) {
        stack<element*> S;
        
        int n = A.size();
        if(n == 0) return 0;
        long mod = pow(10,9) + 7;
        long res = 0;
        
        for(int i = 0 ; i < n ; ++i){
            //sum表示以当前数结尾的最小值之和 last_pos表示从当前数开始 一直到出现比当前数更小的数为止的最后一个坐标
            long sum = 0,last_pos = i;
            
            //维护单调递增栈
            while(!S.empty()){
                auto tmp = S.top();
                if(tmp->val <= A[i]) break;
                S.pop();
            }
            
            
            //如果栈空 说明之前的所有数都比当前数小;否则,从栈顶的下一个数开始到目前为止的所有数 都比 当前数小
            if(S.empty()) 
                last_pos = 0;
            else 
                last_pos = (S.top())->pos + 1;
            
            
            
            //step表示有多少个数比当前数小
            long step = (long)(i - last_pos + 1);
            
            
            sum = (sum + step*A[i] + mod)%mod;
            
            if(!S.empty()) sum = (sum + (S.top())->sum + mod)%mod;
            element *cur = new element(A[i],i,sum);
            S.push(cur);
            res = (res + sum + mod)%mod;
             
        }
        
        return res;
        
    }
    
    
};
