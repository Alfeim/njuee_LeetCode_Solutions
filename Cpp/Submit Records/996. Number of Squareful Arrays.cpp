/********************************************
作者:Alfeim
题目:正方形数组的数目
时间消耗:8ms
解题思路:回溯、DFS、图
********************************************/
class Solution {
public:
    int count;
    int n;
    unordered_map<int,vector<int>> Edge;
    int numSquarefulPerms(vector<int>& A) {
        n = A.size();
        if(n == 0) return 0;
        
        for(int i = 0 ; i < n ; ++i){
            for(int j = i + 1 ; j < n ; ++j){
                if(isSquare(A[i],A[j])){
                    Edge[i].push_back(j);
                    Edge[j].push_back(i);
                }
            }
        }
    
        vector<bool> visited(n,false);
        unordered_set<int> record;
        for(int i = 0 ; i < n; ++i){
            if(record.count(A[i])) continue;
            record.insert(A[i]);
            visited[i] = true;
            dfs(A,visited,i,0);
            visited[i] = false;
        }

        return count;
    }

    void dfs(vector<int>& A,vector<bool> &visited,int curnumber,int pos){
        if(pos == n - 1) {
            count++;
            return;
        }
        
        unordered_set<int> record;
        for(auto i : Edge[curnumber]){
            if(!visited[i] && !record.count(A[i])){
                visited[i] = true;
                record.insert(A[i]);
                dfs(A,visited,i,pos+1);
                visited[i] = false;
            }
        }

        return;
    }

    bool isSquare(int num1,int num2){
        int res = sqrt(num1+num2);
        return pow(res,2) == num1 + num2;
    }
};
