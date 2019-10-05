/********************************************
作者:Alfeim
题目:相似字符串
时间消耗:1308ms
解题思路:先利用相似关系创建图，然后对图进行遍历即可
********************************************/
class Solution {
public:
    unordered_map<string,unordered_set<string>> Graph;
    unordered_set<string> visited;
    queue<string> Q;
    int numSimilarGroups(vector<string>& A) {
        int n = A.size();    
        int res = 0;
        
        //生成图
        for(int i = 0 ; i < n ; ++i){
            for(int j = i + 1 ; j < n ; ++j){
                if(similar(A[i],A[j])){
                    Graph[A[i]].insert(A[j]);
                    Graph[A[j]].insert(A[i]);
                }                
            }
        }
        
        //处理
        for(int i = 0 ; i < n ; ++i){
            if(!visited.count(A[i])){
                bfs(A[i]);
                res++;
            }
        }
        
        return res;
    
        
    }
    
    //BFS处理集合
    void bfs(string cur){  
        Q.push(cur);
        visited.insert(cur);    
        while(!Q.empty()){
            int size = Q.size();
            while(size--){
                auto tmp = Q.front();
                Q.pop();
                for(auto i : Graph[tmp]){
                    if(!visited.count(i)){
                        visited.insert(i);
                        Q.push(i);
                    }
                }
            }
        }
        
        return;
    }
    
    //比较两个单词是否相似
    bool similar(string &word1,string &word2){
        int n = word1.size();
        int count = 0;
        for(int i = 0 ; i < n && count <= 2; ++i) if(word1[i] != word2[i]) count++;
        return count <= 2;
    }
};
