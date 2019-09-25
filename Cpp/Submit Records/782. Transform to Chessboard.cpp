/********************************************
作者:Alfeim
题目:变为棋盘
时间消耗:8ms
解题思路:

最小交换次数实际和 让行首与列首满足性质时的次数相同

参考：https://blog.csdn.net/weixin_42054167/article/details/91802857
********************************************/

class Solution {
public:
    //求最小移动次数
    int movesToChessboard(vector<vector<int>>& board) 
    {
        int n = board.size();
        //任意一个矩形的四个顶点只有三种情况，要么四个0，要么四个1，要么两个0两个1，不会有其他的情况
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(board[0][0] ^ board[i][0] ^ board[0][j] ^ board[i][j])
                {
                    return -1;
                }
            }
        }
        
        int rowSum = 0, colSum = 0, rowDiff = 0, colDiff = 0;
        //10101以这种形式为最终合法棋盘
        //每行的1的个数要么为 n/2，要么为 (n+1)/2
        for(int i = 0; i < n; ++i)
        {
            rowSum += board[0][i];
            colSum += board[i][0];
            rowDiff += (board[0][i] == i % 2);
            colDiff += (board[i][0] == i % 2);
        }
        if(rowSum < n/2 || (n+1)/2 < rowSum)
        {
            return -1;
        }
        if(colSum < n/2 || (n+1)/2 < colSum)
        {
            return -1;
        }
        //10101
        if(n%2) //为奇数个
        {
            if(rowDiff%2) //错位为奇数个
            {
                rowDiff = n - rowDiff; //转为偶数个
            }
            if(colDiff%2) //错位为奇数个
            {
                colDiff = n - colDiff; //转为偶数个
            }
        }
        else
        {
            rowDiff = min(n - rowDiff, rowDiff);
            colDiff = min(n - colDiff, colDiff);
        }
        //每交换1次会修改2个错位
        return (rowDiff + colDiff) / 2;
    }
};
