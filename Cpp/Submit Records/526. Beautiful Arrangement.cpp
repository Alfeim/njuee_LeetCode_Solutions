/********************************************
作者:Alfeim
题目:优美的排列
时间消耗:296ms
解题思路:回溯
********************************************/
class Solution {
public:
    int res;
    int countArrangement(int N) {
        vector<bool> record(N+1,false);
        res = 0;
        dfs(1,N,record);
        return res;
    }
    
    void dfs(int pos,int N,vector<bool>& record){
        if(pos > N){
            res++;
            return;
        }
        
        for(int i = 1 ; i <= N ; ++i){
            if(!record[i] && (i%pos == 0 || pos%i == 0)){
                record[i] = true;
                dfs(pos+1,N,record);
                record[i] = false;
            }   
        }
    }
};
