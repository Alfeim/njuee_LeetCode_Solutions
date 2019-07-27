/********************************************
作者:Alfeim
题目:完美矩形
时间消耗:204ms
解题思路:维护四个边界---最左、最右、最上、最下 同时每次遍历数组时,将对应的点加入到集合中,如果集合
中已经存在该点，就将其删除(因为如过是完美矩形,外部的四个点显然是不会有重复的,所以遇到重复的就认为
是内部点),同时累加矩形面积如果最后矩形的总面积与通过四个边界算出的相同,并且当前集合里只有4个边界对
应的四个点，说明是完美矩形
********************************************/
class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        std::set<std::pair<int,int>> points;
        int left = INT_MAX,bottom = INT_MAX,top = INT_MIN,right = INT_MIN;
        int Area = 0;
        for(auto p : rectangles){
            
            left   = min(p[0],left);
            bottom = min(p[1],bottom);
            right  = max(p[2],right);
            top    = max(p[3],top);
            Area += (p[2] - p[0]) * (p[3] - p[1]);
            
            vector<pair<int,int>> P({make_pair(p[0],p[1]),make_pair(p[0],p[3]),make_pair(p[2],p[1]),make_pair(p[2],p[3])});
            for(auto j : P){
                if(points.count(j) > 0) 
                    points.erase(j);
                else 
                    points.insert(j);
            }
        }
        
        if( (right - left ) * (top - bottom) != Area)
            return false;
        
        if(points.size() == 4 && points.count(make_pair(left,bottom)) > 0 && points.count(make_pair(left,top)) > 0 
                              && points.count(make_pair(right,top)) > 0 && points.count(make_pair(right,bottom)) > 0)
           return true;
        
        return false;
        
    }
};
