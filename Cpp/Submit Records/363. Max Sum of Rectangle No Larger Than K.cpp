/********************************************
作者:Alfeim
题目:矩形区域不超过K的最大数值和
时间消耗:880ms
解题思路:类似于求解矩阵最大子阵和的方式
********************************************/
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
       int m = matrix.size(),n = matrix[0].size();
       if( m == 0 || n == 0)
           return 0;
       int res = INT_MIN;
       //下面的方法其实本质就是求最大子矩阵和
       //其实求最大子矩阵和的思路很清晰,就是分别固定行和列的起始,然后移动行和列的终点
       //习惯上先固定rows_begin和rows_end后再固定cols_begin和cols_end,如果在不优化的情况下,显然时间复杂度是O(m*m*n*n),所以先固定列or行无所谓
       //这里优化的方式参考了lower_bound的方法...确实一时没想到,相当于把搜寻"满足条件的最大数"的复杂度从n降低到了logn,而题目告诉我们行数远远大于
       //列数,我们当然希望这个n代表行了...所以循环最外层是cols,内层是rows
       for(int cols_begin = 0 ; cols_begin < n ; ++cols_begin){ //先固定列的起始位置
           vector<int> RowSum(m,0); //RowSum表示每一行所对应的从cols_begin列开始的前缀和
           for(int cols_end = cols_begin ; cols_end < n ; ++cols_end){ //然后固定列的结束位置
               set<int> Records; 
               int tmpSum = 0;
               Records.insert(0);
               for(int rows = 0 ; rows < m ; ++rows){   //遍历每一行...原本需要分别固定行的起始和终止,但是利用set自动排序的性质可以进行优化
                    RowSum[rows] += matrix[rows][cols_end];
                    tmpSum += RowSum[rows];
                    auto it = Records.lower_bound(tmpSum - k);
                    if(it != Records.end()){
                        if(tmpSum - *it == k)
                            return k;
                        else
                            res = max(tmpSum - *it,res);
                    }
                    Records.insert(tmpSum);
               }
           }
       } 
       return res;  
    }
};
