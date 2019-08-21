/********************************************
作者:Alfeim
题目:大礼包
时间消耗:4ms
解题思路:回溯 + 剪枝
********************************************/
class Solution {
public:
    int res;
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        res = INT_MAX;
        dfs(price,special,needs,0);
        return res;
    }
    
    void dfs(vector<int> &price,vector<vector<int>> &special,vector<int> &needs,int sum){
        int m = needs.size();
        int n = special.size();

       //如果当前要(还能)继续选择大礼包
        for(int i = 0 ; i < n ; ++i){
            bool flag = true;
            for(int j = 0 ; j < m ; ++j){
                if(needs[j] < special[i][j]){
                    flag = false;
                    break;
                }
            }
            
            if(!flag) continue;
            
            if(sum + special[i][m] < res){
                for(int k = 0 ; k < m ; ++k){
                    needs[k] -= special[i][k];
                }
                dfs(price,special,needs,sum + special[i][m]);  
                for(int k = 0 ; k < m ; ++k){
                    needs[k] += special[i][k];
                }

            }

        }
        //当前不选大礼包,而是选择单独买来凑齐
        for(int i = 0 ; i < m ; ++i){
            sum += needs[i] * price[i];
            if(sum > res) return;
        }
        
        res = min(res,sum);

    }
    
};
