/********************************************
作者:Alfeim
题目:安排工作以达到最大受益
时间消耗:1000ms
解题思路:双指针
********************************************/
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>> Nodes;
        int n = difficulty.size();
        for(int i = 0 ; i < n ; ++i){
            Nodes.push_back({difficulty[i],profit[i]});
        }
        
        sort(Nodes.begin(),Nodes.end(),[](const pair<int,int> &first, const pair<int,int> &second){
            if(first.second < second.second) return true;
            else if(first.second > second.second) return false;
            return first.first  < second.first;
        });

        int res = 0;
        for(int i = 0 ; i < worker.size() ; ++i){
            
            int j = n - 1;
            
            for(; j >= 0 ; --j){
                if(Nodes[j].first <= worker[i]) break; 
            }
            
            res += j >= 0 ? Nodes[j].second : 0;
            
            
        }
        
        return res;
        
    }
    

    
};
