/********************************************
作者:Alfeim
题目:回旋镖的数目
时间消耗:592ms
解题思路:哈希表
********************************************/
class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        unordered_map<int,int> record; 
        int n = points.size();
        int res = 0;
        for(int i = 0 ; i < n ; ++i){
            for(int j = 0 ; j < n ; ++j){
                if(j == i ) continue;
                
                int d = distance(points[i][0],points[j][0],points[i][1],points[j][1]);
                if(record.count(d) > 0){
                    res += 2*record[d];
                }
                record[d]++;
            }
            record.clear();
        }
        
        return res;
        
    }
    
    int distance(int x1, int x2,int y1,int y2){
        return pow(x1-x2,2) + pow(y1-y2,2);
    }
    
    
};
