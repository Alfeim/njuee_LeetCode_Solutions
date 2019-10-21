/********************************************
作者:Alfeim
题目:最大的以1为边界的正方形
时间消耗:28ms
解题思路:DP
********************************************/
class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n == 0) return 0;
        int m = grid[0].size();
        if(m == 0) return 0;

        
        //dp_left表示对于某个点能向左延伸的最大长度
        //dp_up表示对于某个点能向上延伸的最大长度
        vector<vector<int>> dp_up(n,vector<int>(m,0));
        vector<vector<int>> dp_left(n,vector<int>(m,0));
       
        dp_left[0][0] = grid[0][0];
        dp_up[0][0] = grid[0][0];

        int res = grid[0][0];
        for(int i = 1 ; i < n ; ++i){
            if(grid[i][0] == 1){
                res = 1;
                dp_up[i][0] = dp_up[i-1][0] + 1;
                dp_left[i][0] = 1;
            } 
        }

        for(int i = 1 ; i < m ; ++i){
            if(grid[0][i] == 1){
                res = 1;
                dp_left[0][i] = dp_left[0][i-1] + 1;
                dp_up[0][i] = 1;
            } 
        }

        for(int i = 1 ; i < n ; ++i){
            for(int j = 1 ; j < m ; ++j){
                if(grid[i][j] == 0) continue;
                dp_left[i][j] = dp_left[i][j-1] + 1;
                dp_up[i][j] = dp_up[i-1][j] + 1;
                int border = min(dp_left[i][j],dp_up[i][j]);
                for(int len = border ; len >= 1 ; --len){
                    if(dp_up[i][j- len + 1] >= len && dp_left[i- len + 1][j] >= len){
                        res = max(res,len);
                        break;
                    }
                }
            }
        }

        return res*res;

    }
};
