/********************************************
作者:Alfeim
题目:和至少为K的最短子数组
时间消耗:180ms
解题思路:双向递增队列，存储前缀和的下标

之所以要保持前缀和是递增，举个例子

比如P[10] = 10, P[5] = 5,那么区间6-10的和也就是4，假设D = 4，则此时区间是有效的，长度为5

那么假如在P[10]前存在比P[10]更大的前缀和,那么显然对应区间的也是有效的，且更短


********************************************/
class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        int n = A.size(),res = INT_MAX;
        
        vector<long> PreSum(n + 1,0);
        deque<long> D;
        
        for(int i = 0 ; i < n ; ++i){
            PreSum[i + 1] = PreSum[i] + A[i];
        }
        
        
        for(int i = 0 ; i <= n ; ++i){
            
            while(!D.empty() && PreSum[i] <= PreSum[D.back()] )
                D.pop_back();
            
            while(!D.empty() && PreSum[i] - PreSum[D.front()] >= K){
                 int pos = D.front();
                 res = min(res,i - pos);
                 D.pop_front();
            }

            D.push_back(i);
        }
        
        
        return res == INT_MAX ? -1 : res;
        
    }
};


