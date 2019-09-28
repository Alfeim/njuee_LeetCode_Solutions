/********************************************
作者:Alfeim
题目:最短的桥
时间消耗:36ms
解题思路:BFS
********************************************/
class Solution {
public:
    queue<pair<int,int>> Q;
    
    int shortestBridge(vector<vector<int>>& A) {
        int m = A.size(),n = A[0].size();
        
        bool flag = true;
        
        for(int i = 0 ; i < m && flag ; ++i){
            for(int j = 0 ; j < n ; ++j){
                if(A[i][j] == 1){
                    flag = false;
                    transform(i,j,A);
                    break;
                }
            }
        }
        

        int step = 0,row = 0,col = 0;
        
        while(!Q.empty()){
            int size = Q.size();
            
            while(size--){
                auto cur = Q.front();
                Q.pop();
                row = cur.first;
                col = cur.second;
                
                if(row + 1 < m && A[row+1][col] != 2){
                    if(A[row+1][col] == 1) return step;
                    A[row+1][col] = 2;
                    Q.push({row+1,col});
                }
                
                if(row - 1 >= 0 && A[row-1][col] != 2){
                    if(A[row-1][col] == 1) return step;
                    A[row-1][col] = 2;
                    Q.push({row-1,col});
                }
                
                if(col + 1 < m && A[row][col+1] != 2){
                    if(A[row][col+1] == 1) return step;
                    A[row][col+1] = 2;
                    Q.push({row,col+1});
                }
                
                if(col - 1 >= 0 && A[row][col-1] != 2){
                    if(A[row][col-1] == 1) return step;
                    A[row][col-1] = 2;
                    Q.push({row,col-1});
                }
                
            }
            
            step++;
        }
        
        
        return step;
        
        
    }
    
    void transform(int i,int j,vector<vector<int>> &A){
        
        A[i][j] = 2;
        
        Q.push({i,j});
        
        int m = A.size(),n = A[0].size();
        
        if(i + 1 <  m && A[i+1][j] == 1) transform(i+1,j,A);
        if(i - 1 >= 0 && A[i-1][j] == 1) transform(i-1,j,A);
        if(j + 1 <  n && A[i][j+1] == 1) transform(i,j+1,A);
        if(j - 1 >= 0 && A[i][j-1] == 1) transform(i,j-1,A);
        
    }
    
};
