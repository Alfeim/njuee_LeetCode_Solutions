/********************************************
作者:Alfeim
题目:最小基因变化
时间消耗:4ms
解题思路:同单词接龙问题,BFS思路
相似题目:127. Word Ladder
********************************************/
class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        vector<char> GENE({'A','T','C','G'});
        unordered_set<string> visited;
        unordered_set<string> dict(bank.begin(),bank.end());
        queue<string> Q;
        
        int res = 0;
        
        Q.push(start);
        visited.insert(start);
     
        while(!Q.empty()){
            int size = Q.size();
            while(size--){
                auto curword(Q.front());
                int n = curword.size();
                Q.pop();
                for(int i = 0 ; i < n ; ++i){
                    string tmp(curword);
                    for(auto j : GENE){
                        tmp[i] = j;
                        if(tmp == end && dict.count(end) > 0)
                            return res + 1;
                        if(dict.count(tmp) == 0 || visited.count(tmp) > 0)
                            continue;
                        visited.insert(tmp);
                        Q.push(tmp);
                    }  
                }
            }  
            res++;
        }   
         return -1;
    }
};
