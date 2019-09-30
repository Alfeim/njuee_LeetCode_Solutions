/********************************************
作者:Alfeim
题目:最小矩形面积
时间消耗:1428ms
解题思路:
哈希表,以x为顺序进行遍历,每次记录对应(y1,y2)所在
的x坐标
********************************************/
class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        
        map<int,vector<int>> M1;
        map<pair<int,int>,int> edge;
        
        int res = INT_MAX;
        
        for(auto i : points) M1[i[0]].push_back(i[1]);
        
        for(auto m : M1){
            int n = m.second.size();
            
            for(int i = 0 ; i < n ; ++i){
                for(int j = i + 1 ; j < n ; ++j){ 
                    int y0 = m.second[i] < m.second[j] ? m.second[i] : m.second[j];
                    int y1 = ( y0 == m.second[i] ) ? m.second[j] : m.second[i];
                    
                    if(y0 == y1) continue;
                    
                    if(edge.count({y0,y1})){   
                        res = min((m.first - edge[{y0,y1}]) * (y1-y0) ,res);
                    }
                    
                    edge[{y0,y1}] = m.first;
                }
            }
                
        }
        
        
        return res == INT_MAX ? 0 : res;
        
    }
};
