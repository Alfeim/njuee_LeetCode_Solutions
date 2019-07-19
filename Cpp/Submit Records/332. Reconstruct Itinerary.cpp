/********************************************
作者:Alfeim
题目:重新安排行程
时间消耗:40ms
解题思路:dfs,注意进行最优化剪枝
********************************************/
class Solution {
public:
    vector<vector<string>> res;
    map<string,map<string,int>> M;
    int target;
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        target = tickets.size();
        for(auto i : tickets)
            M[i[0]][i[1]]++;
        
        vector<string> tmp(1,"JFK");
        for(auto &j : M["JFK"]){
            j.second--;
            tmp.push_back(j.first);
            if(Solve(tmp,1,j.first))
                break;
            tmp.pop_back();
            j.second++;
        }
        
        return res[0];
    }
    
    bool Solve(vector<string> &tmp,int count,string last){
        if(count == target){
            res.push_back(tmp);
            return true;
        }  
        for(auto &i : M[last]){
            if(i.second <= 0) continue;
            i.second--;
            tmp.push_back(i.first);
            if(Solve(tmp,count+1,i.first))
                return true;
            tmp.pop_back();
            i.second++;
        }
        
        return false;
    }
    
};
