/********************************************
作者:Alfeim
题目:对角线遍历
时间消耗:200ms
解题思路:细节题
********************************************/
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        bool flag = true; //flag为true即从左下穿到右上
        vector<int> res;
        if(matrix.empty())
            return res;
        int m = matrix.size();
        int n = matrix[0].size();
        for(int level = 0 ; level < m+ n - 1; ++level){
            if(flag){
                int i = level  < m ? level : m-1;
                for(int j = level - i ;  i >= 0 && j < n ;--i,++j)
                    res.push_back(matrix[i][j]);
            }else{
                int i = level  < n ? 0 : level - n + 1;
                for(int j = level - i ; j >= 0 && i < m ; ++i,--j)
                    res.push_back(matrix[i][j]);
            }
            
            flag = !flag;
        }
        
        return res;
   
    }
};
