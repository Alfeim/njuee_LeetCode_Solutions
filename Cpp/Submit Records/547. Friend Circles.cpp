/********************************************
作者:Alfeim
题目:朋友圈
时间消耗:28ms
解题思路:dfs
********************************************/
class Solution {
public:
    int res;
    int findCircleNum(vector<vector<int>>& M) {
        res = 0;
        int n = M.size();
        for(int i = 0 ; i < n ; ++i){
            for(int j = 0 ; j < n ; ++j){
                if(M[i][j] == 1) {
                    res++;
                    dfs(M,i);
                    break;
                }
            }
        } 
        return res;   
    }
    
    void dfs(vector<vector<int>>& M,int student){
        int n = M.size();
        for(int i = 0 ; i < n ; ++i){
            if(M[student][i] == 1){
                M[student][i] = 2;
                M[i][student] = 2;
                if(i != student ) dfs(M,i);
            }   
        }
    }
    
};
