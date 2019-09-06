/********************************************
作者:Alfeim
题目:金字塔转换矩阵
时间消耗:8ms
解题思路:DFS
********************************************/
class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string,vector<char>> ALLOW;
        unordered_set<string> visited;
        for(auto i : allowed){
            ALLOW[i.substr(0,2)].push_back(i[2]);    
        }
        return Solve(bottom,"",bottom.size() - 1,0,ALLOW,visited);
        
    }
    
    bool Solve(string curNumber,string nextNumber,int nextLen,int count, unordered_map<string,vector<char>> &ALLOW, unordered_set<string> &visited){
        if( nextLen == 1 && count == 1 ) return true;
        
        if(count == nextLen){
            if(visited.count(nextNumber) > 0) 
                return false;
            
            visited.insert(nextNumber);
            return Solve(nextNumber,"",nextLen-1,0,ALLOW,visited);
        }
        
        string tmp = curNumber.substr(count,2);
        for(auto c : ALLOW[tmp]){
            if(Solve(curNumber,nextNumber + c,nextLen,count+1,ALLOW,visited)) return true;
        }
        return false;
    }
    
};
