/********************************************
作者:Alfeim
题目:贴纸拼词
时间消耗:204ms
解题思路:dfs
********************************************/
class Solution {
public:
    int minStickers(vector<string>& stickers, string target) {
        int n = stickers.size(),m = target.size();
        unordered_map<string,int> record;
        
        vector<vector<int>> word_counts(n,vector<int>(26,0));
     
        //预处理
        record[""] = 0;
        for(int i = 0 ; i < n ; ++i){
            for(auto c : stickers[i]){
                word_counts[i][c - 'a']++;
            }
        }
        
        return dfs(record,word_counts,target);
        
    }
    
    
    int dfs(unordered_map<string,int> &record,vector<vector<int>> &word_counts,string target){
        
        if(record.count(target) > 0)  return record[target];
        
        vector<int> target_counts(26,0);    
        for(auto i : target) target_counts[i - 'a']++;
        int MinStep = INT_MAX,n = word_counts.size();
        for( int i = 0 ; i < n ; ++i ){
            if( word_counts[i][ target[0] - 'a'] == 0 ) continue;     
            string next_target;
            for(int j = 0 ; j < 26 ; ++j){
                if(target_counts[j] >= word_counts[i][j])
                    next_target += string(target_counts[j] - word_counts[i][j], j + 'a');                
            }
            
            int tmpStep = dfs(record,word_counts,next_target);
            if( tmpStep != -1) MinStep = min(1 + tmpStep,MinStep);   
        }
        
        record[target] = (MinStep == INT_MAX )? -1 : MinStep;
        return record[target];
    }
    
    
};










