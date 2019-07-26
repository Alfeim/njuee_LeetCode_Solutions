/********************************************
作者:Alfeim
题目:除法求值
时间消耗:0ms
解题思路:DFS或者Floyd算法
********************************************/
class Solution {
public:
    map<string,map<string,double>> G;
    vector<double> res;
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int m = equations.size();
        res = vector<double>(queries.size(),-1.0);
        for(int i = 0 ; i < m ; ++i){
            G[equations[i][0]][equations[i][1]] = values[i];
            G[equations[i][1]][equations[i][0]] = (1.0)/values[i];
        }
        int count = 0;
        for(auto i : queries){
            set<string> visited;
            Solve(i[0],i[1],visited,1.0,count);
            count++;
        }
        
        return res;
    }
    
    bool Solve(string begin,string end,set<string> &visited,double tmp,int n){
        if(begin == end && G.count(begin) > 0){
            res[n] = tmp;
            return true;
        }

        for(auto i : G[begin]){
            if(visited.count(i.first) == 0){
                visited.insert(i.first);
                if(Solve(i.first,end,visited,tmp*i.second,n))
                    return true;
                visited.erase(i.first);        
            }   
        }
        
        return false;
        
    }
};
