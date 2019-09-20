/********************************************
作者:Alfeim
题目:车队
时间消耗:48ms
解题思路:排序
********************************************/
class Solution {
public:

    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        if(n == 0) return 0;
        
        
        int res = 1;
        vector<pair<int,int>> tmp;
        for(int i = 0 ; i < n ; ++i ){
            tmp.push_back({position[i],speed[i]});            
        }
        
        sort(tmp.begin(),tmp.end(),[](const pair<int,int>& a,const pair<int,int>& b){return a.first > b.first;});
        
        for(int i = 1 ; i < n ; ++i){
            int j = i - 1;
            for(; j >= 0 ; j--){
               if( (long)(target - tmp[j].first)*(long)tmp[i].second >= (long)(target - tmp[i].first)*(long)tmp[j].second ) break;
            }    
            if(j < 0) res++;
        }
        
        return res;
    }
};
