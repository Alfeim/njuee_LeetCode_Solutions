/********************************************
作者:Alfeim
题目:掉落的方块
时间消耗:116ms
解题思路:
比较直白的做法,建立一个结构体保存当前方块的起始、终点与高度

然后每次新掉落方块时,都遍历数组查看是否存在交集

如果存在交集就让当前方块的高度取交集中最大的一个加上本方块的高度
********************************************/
class Solution {
public:
    struct block{
        int begin;
        int end;
        int high;
        block(int _begin,int _end,int _high):begin(_begin),end(_end),high(_high){};
    };
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        vector<block*> BLOCK;
        vector<int> res;
        int tmpMax = 0;
        
        for(auto i : positions){
            tmpMax = max(tmpMax,i[1]);
            block *cur = new block(i[0],i[0] + i[1],i[1]);
            for(auto b : BLOCK){
                if( max(i[0],b->begin) < min(i[0] + i[1],b->end)){
                    tmpMax = max(b->high + i[1],tmpMax);
                    cur->high = max(cur->high,b->high + i[1]);
                } 
            }
            BLOCK.push_back(cur);
            res.push_back(tmpMax);
        }
        return res;
    }
};
