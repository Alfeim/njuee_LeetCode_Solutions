/********************************************
作者:Alfeim
题目:不同路径3
时间消耗:4ms
解题思路:BFS
********************************************/
class Solution {
public:
    struct node{
        int i;
        int j;
        int state;
        node(int _i,int _j,int _state):i(_i),j(_j),state(_state){};
    };

    int uniquePathsIII(vector<vector<int>>& grid) {
        
        int m = grid.size();
        if(m == 0) return 0;

        int n = grid[0].size();
        if(n == 0) return 0;

        node startnode(0,0,0);
        int res = 0;

        //相当于将二维方格压缩为一维方格
        int offset = 0;
        for(int i = 0,cur = 0; i < m ; ++i){
            for(int j = 0 ; j < n ; ++j){
                offset = i * n + j;
                if(grid[i][j] == 1) {
                    startnode.i = i;
                    startnode.j = j;
                    startnode.state |= (1 << offset);
                }else if(grid[i][j] == -1){
                    startnode.state |= (1 << offset);
                }

            }
        }

        //定义当前状态(表示访问过哪些节点,原本为-1的节点均设置为“访问过”)和最终状态
        int finalstate = (1 << m*n) - 1;
        queue<node> Q;
        Q.push(startnode);
        while(!Q.empty()){
            auto cur = Q.front();
            Q.pop();

            int i = cur.i;
            int j = cur.j;
            int tmpstate = cur.state;
            offset = i*n + j;
           
            if(i > 0  && ((tmpstate >> (offset - n)) & 1)  == 0 ){
                int nextstate = tmpstate | (1 <<(offset - n ));
                if(grid[i-1][j] == 2 && nextstate == finalstate ) res++;
                else{
                    if(grid[i-1][j] != 2) Q.push(node(i-1,j,nextstate));
                }
            }

            if(i + 1 < m && ((tmpstate >> (offset + n)) & 1)  == 0 ){
                int nextstate = tmpstate | (1 <<(offset + n ));
                if(grid[i+1][j] == 2 && nextstate == finalstate ) res++;
                else{
                    if(grid[i+1][j] != 2)Q.push(node(i+1,j,nextstate));
                }
            }

            if(j > 0 && ((tmpstate >> (offset - 1)) & 1)  == 0 ){
                int nextstate = tmpstate | (1 <<(offset - 1 ));
                if(grid[i][j-1] == 2 && nextstate == finalstate ) res++;
                else{
                    if(grid[i][j-1] != 2 )Q.push(node(i,j-1,nextstate));
                }
            }

            if(j + 1< n  && ((tmpstate >> (offset + 1)) & 1)  == 0 ){
                int nextstate = tmpstate | (1 <<(offset + 1 ));
                if(grid[i][j+1] == 2 && nextstate == finalstate ) res++;
                else{
                    if(grid[i][j+1] != 2) Q.push(node(i,j+1,nextstate));
                }
            }

        }

    return res;
    }
};
