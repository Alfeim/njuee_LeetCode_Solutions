/********************************************
作者:Alfeim
题目:重塑矩阵
时间消耗:82ms
解题思路:..没啥好说的
********************************************/
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int m = nums.size();
        if(m == 0) return nums;
        int n = nums[0].size();
        if( m*n != r*c ) return nums;
        vector<vector<int>> res(r,vector<int>(c,0));
        
        int row = 0,col = 0,pos = 1;
        for(int i = 0 ; i < m ; ++i){
            for(int j = 0 ; j < n ; ++j){
                row = (pos - 1)/c;
                col = pos%c == 0 ? c - 1 : pos % c - 1;
                res[row][col] = nums[i][j];  
                pos++;
            }
        }   
        return res;
    }
};
