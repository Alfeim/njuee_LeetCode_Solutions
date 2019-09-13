/********************************************
作者:Alfeim
题目:有效的井字游戏
时间消耗:12ms
解题思路:DFS
********************************************/
class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        vector<string> tmp(3,"   ");
        int left = 0;
        for(auto i : board){
            for(auto j : i ) if(j != ' ') left++;
        }

        return Solve(board,tmp,left,'X');
        
    }
    
    bool Solve(vector<string>& board,vector<string>& tmp,int left,char word){
        if(left == 0) return true;
        
        for(int i = 0 ; i < 3 ; ++i){
            for(int j = 0 ; j < 3 ; ++j){  
                if(tmp[i][j] == ' ' && board[i][j] == word){
                    
                    bool end = false;
                    left--;
                    tmp[i][j] = word;
                    char next_word = (word == 'X') ? 'O' : 'X';

                    if(isEnd(tmp,i,j)){
                        end = true;
                        if(left == 0)  return true;
                    }
                   
                    if(!end && Solve(board,tmp,left,next_word)) return true;
                    
                    tmp[i][j] = ' ';  
                    left++;
                }
            }
        }
        
        return false;
    }
    
   
    bool isEnd(vector<string>& tmp,int i,int j){
        
        //对角线的两种情况
        if( i == j ){
            if(tmp[0][0] == tmp[1][1] && tmp[1][1] == tmp[2][2]) return true;
        }
                    
        if(i + j == 2){
            if(tmp[2][0] == tmp[1][1] && tmp[1][1] == tmp[0][2]) return true;
        }
           
        //列的情况
        if(tmp[0][j] == tmp[1][j] && tmp[1][j] == tmp[2][j])  return true;
                   
                    
        //行的情况
        if(tmp[i][0] == tmp[i][1] && tmp[i][1] == tmp[i][2] ) return true;
        
        return false;
                        
    }

    
};
