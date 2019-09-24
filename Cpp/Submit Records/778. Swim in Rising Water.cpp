/********************************************
作者:Alfeim
题目:水位上升的泳池中游泳
时间消耗:40ms
解题思路:自定义排序 二分搜索
********************************************/
class Solution {
public:
    struct node{
        int i;
        int j;
        int val;
        node(int _i,int _j,int _val):i(_i),j(_j),val(_val){};
    };
    
    struct cmp{
      bool operator()(const node &a,const node &b) const{
          if(a.val < b.val) return true;
          return false;
      }  
    };
    
    int swimInWater(vector<vector<int>>& grid) {
        int t = 0,n = grid.size();        
        vector<vector<int>> pos{{-1,0},{0,1},{1,0},{0,-1}};
        vector<vector<bool>> visited(n,vector<bool>(n,false));
        
        set<node,cmp> S;
        visited[0][0] = true;
        S.insert(node(0,0,grid[0][0]));

        
        while(!S.empty()){
            auto cur = S.begin();
            if(t < cur->val) t = cur->val; 
            if(cur->i == n - 1 && cur->j == n - 1) return t;     
            
            for(auto p : pos){
    
                int newi = cur->i + p[0];
                int newj = cur->j + p[1];
                
                if(newi >= 0 && newj >= 0 && newi < n && newj < n && !visited[newi][newj]){
                    visited[newi][newj] = true;
                    S.insert(node(newi,newj,grid[newi][newj]));
                }
                
            }
            
            S.erase(cur);
            
        }
        
        return 0;
        
        
    }
    

    
    
    
};
