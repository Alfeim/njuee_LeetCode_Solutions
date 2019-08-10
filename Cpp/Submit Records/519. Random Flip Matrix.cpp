/********************************************
作者:Alfeim
题目:随机翻转矩阵
时间消耗:28ms
解题思路:只需要用降维的思想..把二维数组压缩成一维，我们只需要知道这个一维数组的总长度即可
每次随机时就想象成从一维数组中抽取一个点,根据该点所在位置是可以倒推出原本所在 的二维数组中的行列信息的！
********************************************/
class Solution {
public:
    Solution(int n_rows, int n_cols):Row(n_rows),Col(n_cols){
 
    }
    
    vector<int> flip() {
        int multi = Row * Col;
        if(record.size() >= multi)
            return {};
        
        while(1){
            int pos = rand()%multi;
            if(record.count(pos) > 0)
                continue;
            int real_row = pos/Col;
            int real_col = pos%Col;
            record.insert(pos);
            return {real_row,real_col};
        }
        
        return {};
    }
    
    void reset() {
      
        record.clear();
        
    }
    
    int Row;
    int Col;
    set<int> record;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n_rows, n_cols);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */
