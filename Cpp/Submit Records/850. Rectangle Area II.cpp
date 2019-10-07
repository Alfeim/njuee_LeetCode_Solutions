/********************************************
作者:Alfeim
题目:矩形面积Ⅱ
时间消耗:40ms
解题思路:

扫描线算法

先扫描所有可能的y坐标,并排序、去重

然后算出每个y坐标区段的矩形面积

累计每一部分的面积即是答案

********************************************/
class Solution {
public:

    int rectangleArea(vector<vector<int>>& rectangles) {
        //扫描线算法
        long long res = 0;
        long long mod = 1000000007;
  
        vector<int> Ypos;
        
        for(auto i : rectangles){
            Ypos.push_back(i[1]); 
            Ypos.push_back(i[3]);
        }
        
        sort(Ypos.begin(),Ypos.end());
        Ypos.erase(unique(Ypos.begin(),Ypos.end()),Ypos.end());
        
        int n = Ypos.size();
        
        for(int i = 0 ; i < n - 1 ; ++i){
            long long width = 0,height = Ypos[i+1] - Ypos[i];
            vector<pair<int,int>> Container;
            
            for(auto r : rectangles){
                if(r[1] <= Ypos[i] && r[3] >= Ypos[i+1]){
                    Container.push_back({r[0],r[2]});
                }    
            }
            
            if(Container.empty()) continue;
            
            sort(Container.begin(),Container.end());
            
            for(int k = 0 ; k < Container.size() - 1 ; ++k){
                if(Container[k+1].first <= Container[k].second){
                    Container[k].second = max(Container[k+1].second,Container[k].second);
                    Container.erase(Container.begin() + k + 1);
                    k--;
                }    
            }   
            
            for(auto i : Container) width += (i.second - i.first);
            
            res = (res + width*height + mod)%mod;    
        }
        
        
        return res;
        
    }
};
