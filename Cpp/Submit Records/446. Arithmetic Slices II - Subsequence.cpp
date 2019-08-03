/********************************************
作者:Alfeim
题目:划分等差子序列2
时间消耗:1011ms
解题思路:动态规划
相似题目：413. Arithmetic Slices
**************************************
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        int res = 0;
        vector<unordered_map<long long,int>> record(n) ;
        for(int i = 1 ; i < n ; ++i){
            for(int j = 0 ; j < i ; ++j){
               long long diff = (long long)A[i] - (long long)A[j];
               int sum = 0;
               if(record[j].count(diff) > 0)
                   sum = record[j][diff];
               
               record[i][diff] += sum + 1;
               res += sum; 
            }
        }
        
        return res;
        
    }
};
