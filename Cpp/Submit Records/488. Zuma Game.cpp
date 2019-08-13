/********************************************
作者:Alfeim
题目:祖玛游戏
时间消耗:8ms
解题思路:dfs
********************************************/
class Solution {
public:
    unordered_map<char,int> record;
    int result;
    int findMinStep(string board, string hand) {
        for(auto i : hand) record[i]++;
        result = dfs(board + '#');
        return result == 6 ? - 1 : result;
        
    }
    
    
    int dfs(string board){
        string boardstr = ZuMa_unique(board);
        if(boardstr == "#") return 0;
        int i = 0;
        int count = 0;
        int res = 6;
        int n = boardstr.size();
        for(int j = 0 ; j < n ; ++j){
            if(boardstr[j] == boardstr[i])
                continue;
            count = 3 - (j - i);
            if(record[boardstr[i]] >= count){
                record[boardstr[i]] -= count;
                res = min(res,count + dfs(boardstr.substr(0,i) + boardstr.substr(j)));
                record[boardstr[i]] += count;
            }
            i = j;
        }
        
        return res;
    }
        
        
    string ZuMa_unique(string boardstr){
        int i = 0;
        int n = boardstr.size();
        for(int j = 0 ; j < n ; ++j){
            if(boardstr[j] == boardstr[i])
                continue;
            if(j - i >= 3)
                return ZuMa_unique(boardstr.substr(0,i) + boardstr.substr(j));
            else
                i = j;    
        }
        return boardstr;
    }
    
};
