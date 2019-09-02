
/********************************************
作者:Alfeim
题目:账户合并
时间消耗:160ms
解题思路:并查集
********************************************/
class Solution {
public:
    int parents[1000];
    vector<vector<string>> res;
    unordered_map<string,int> account_user;
    unordered_map<int,vector<string>> user_mails;
    
    int find(int x){
        if(parents[x] == x) return x;
        parents[x] = find(parents[x]);
        return parents[x];
    }
    
    void Union(int x,int y){
        int _x = find(x);
        int _y = find(y);
        if(_x == _y) return;
        parents[_y] = _x;
    }
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        for(int i = 0 ; i < 1000 ; ++i) parents[i] = i;
        int m = accounts.size();
        for(int i = 0 ; i < m ; ++i){
            int n = accounts[i].size();
            for(int j = 1 ; j < n ; ++j){
                if(account_user.count(accounts[i][j]) > 0) Union(account_user[accounts[i][j]],i);
                else account_user[accounts[i][j]] = i;
            }
        }
        
        for(auto i : account_user){
            int pos = find(i.second);
            if(user_mails.count(pos) == 0) user_mails[pos].push_back(accounts[pos][0]);
            user_mails[pos].push_back(i.first);
        }
        
        for(auto i : user_mails){
            sort(i.second.begin() + 1,i.second.end());
            res.push_back(i.second);    
        }
        
        return res;
    }
};
