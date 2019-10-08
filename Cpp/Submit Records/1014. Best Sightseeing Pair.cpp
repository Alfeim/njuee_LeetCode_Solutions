/********************************************
作者:Alfeim
题目:最佳观光组合
时间消耗:108ms
解题思路: 
将式子A[i] + A[j] + i - j拆成两个部分即
A[i] + i 和 A[j] - j 即可

实际就是求最大的F(i) + F(j)

********************************************/
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        int n = A.size();
        
        int Ipart = max(A[0] + 0 , A[1] + 1);    
        int Jpart = 0;
        int res = A[0] + A[1] - 1;
        
        for(int i = 2 ; i < n ; ++i){
            Jpart = A[i] - i;
            res = max(res,Ipart + Jpart);
            if(A[i] + i > Ipart) Ipart = A[i] + i;
        }
        
        return res;
  
    }

};
