/********************************************
作者:Alfeim
题目:最短单词距离2
时间消耗:84ms
解题思路:哈希表+二分搜索
********************************************/
class WordDistance {
public:
    WordDistance(vector<string>& words) {
        int n = words.size();
        for(int i = 0 ; i < n ; ++i) Pos[words[i]].push_back(i);
    }
    
    int shortest(string word1, string word2) {
        int res = INT_MAX;
        for(auto i : Pos[word1]){
            auto right = lower_bound(Pos[word2].begin(),Pos[word2].end(),i);
            
            if(right == Pos[word2].end()){
                res = min(res,abs(Pos[word2].back() - i));
                break;
            }
            
            res = min(res,abs(*right - i));
            
            if(right == Pos[word2].begin()) continue;
            auto left = right;left--;
            res = min(res,abs(*left - i));
        }

      return res;  
        
    }
    
private:
    unordered_map<string,vector<int>> Pos;
    
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(words);
 * int param_1 = obj->shortest(word1,word2);
 */
