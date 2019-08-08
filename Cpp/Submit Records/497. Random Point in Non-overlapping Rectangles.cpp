/********************************************
作者:Alfeim
题目:非重叠矩形中的随机点
时间消耗:216ms
解题思路:利用面积来进行划分,利用map自动排序确定范围

注意,这里的面积指的是某个矩形包含的点数,所以不是真正
的面积,因为边上的点也算,比如2*2的矩形实际有9个点.
所以算长宽时都要+1
********************************************/
class Solution {
public:
    Solution(vector<vector<int>>& rects):Rects(rects){
        int sumArea = 0;
        int n = rects.size();
        for(int i = 0 ; i < n ; ++i){
            int tmpArea = (rects[i][2] - rects[i][0] + 1) * (rects[i][3] - rects[i][1] + 1);
            sumArea += tmpArea;
            record[sumArea] = i;
        }
        All = sumArea;
    }
    
    vector<int> pick() {
        int randArea = rand()%(All + 1);
        auto it = record.upper_bound(randArea);
        int pos = it->second;
        int x = rand()%(Rects[pos][2] - Rects[pos][0] + 1) + Rects[pos][0];
        int y = rand()%(Rects[pos][3] - Rects[pos][1] + 1) + Rects[pos][1];
        return {x,y};
        
    }
    vector<vector<int>> Rects;
    map<int,int> record;
    int All;
    
};
