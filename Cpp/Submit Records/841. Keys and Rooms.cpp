/********************************************
作者:Alfeim
题目:钥匙和房间
时间消耗:12ms
解题思路:DFS
********************************************/
class Solution {
public:
    stack<int> S;
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n,false);
        
        visited[0] = true;
        S.push(0);
        int counts = 1;
        
        while(!S.empty()){
            auto cur = S.top();
            S.pop();
            for(auto v : rooms[cur]){
                if(!visited[v]){
                    S.push(v);
                    counts++;
                    visited[v] = true;
                } 
            }
        }
        
        return counts == n;
    }
    
   
    
};
