/********************************************
作者:Alfeim
题目:有效的正方形
时间消耗:8ms
解题思路:数学
26 分钟前
把所有点与点之间的距离都遍历一遍... 如果是正方形,最后一定只有两种距离 且短距离是长距离的一半(开平方了) 
且短距离的记录有8个(每个点都有两条相邻边,所以是2*4) 长距离的记录有4个(4次对角线)
********************************************/
class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        map<int,int> lenth;
        vector<vector<int>> points({p1,p2,p3,p4});
        for(int i = 0 ; i < 4 ; ++i){
            for( int j = 0 ; j < 4 ; ++j){
                if(i != j){
                    int len = (points[i][0] - points[j][0])*(points[i][0] - points[j][0]) + (points[i][1] - points[j][1])*(points[i][1] - points[j][1]);
                    lenth[len]++;
                }
            }
        }
        
        if(lenth.size() != 2) return false;
        auto it1 = lenth.begin();
        auto it2 = it1;
        it2++;
            
        return it1->first * 2 == it2->first && it1->second == 8 && it2->second == 4; 
 
    }
};
