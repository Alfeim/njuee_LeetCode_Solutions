/********************************************
作者:Alfeim
题目:甲板上的战舰
时间消耗:0ms
解题思路:遍历所有点,遇到X就让计数+1；如果该点的上方或者左侧存在X，就让计数-1；
********************************************/
class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        int res = 0;
        for(int i = 0 ; i < m ; ++i){
            for(int j = 0 ; j < n ; ++j){
                if(board[i][j] == '.')
                    continue;
                res++;
                if(j - 1 >= 0 && board[i][j-1] == 'X')
                    res--;
                
                if(i - 1 >= 0 && board[i-1][j] == 'X')
                    res--;
            }
        }
        
        return res;
        
    }
};
