/********************************************
作者:Alfeim
题目:活字印刷
时间消耗:56ms
解题思路:dfs 全排列
********************************************/
class Solution {
public:
    unordered_set<string> record;
    int res;
    int n;
    int numTilePossibilities(string tiles) {
        n = tiles.size();
        res = 0;
        dfs(0,tiles);
        return res;
    }
    
    void dfs(int pos,string &tiles){
        if(pos >= n) return;
        
        vector<bool> visited(26,false);
        
        for(int i = pos; i < n ; ++i){
            
            if(visited[tiles[i] - 'A']) continue;
            
            visited[tiles[i] - 'A'] = true;
            
            swap(tiles[pos],tiles[i]); 
            
            if(!record.count(tiles.substr(0,pos+1))){
                res++;
                record.insert(tiles.substr(0,pos+1));
            }
            
            dfs(pos+1,tiles);
            
            swap(tiles[pos],tiles[i]);
        }
    }
    
};
