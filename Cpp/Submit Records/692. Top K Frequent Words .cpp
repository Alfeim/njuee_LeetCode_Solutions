/********************************************
作者:Alfeim
题目:前k个高频单词
时间消耗:24ms
解题思路:优先级队列
********************************************/
class Solution {
public:
    struct Node{
        string word;    
        int freq;
        Node(string str,int _freq):word(str),freq(_freq){};
    };
    
    struct cmp{
        bool operator()(Node a,Node b){
            if(a.freq > b.freq) return true;
            else if(a.freq < b.freq) return false;
            
            int m = a.word.size();
            int n = b.word.size();
            int i = 0;
            for(; i < m && i < n ; ++i){
                if(a.word[i] > b.word[i]) return false;
                else if(a.word[i] < b.word[i]) return true;
            }
            
            return i < n ; 
        }
        
    };
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> freq;
        priority_queue<Node,vector<Node>,cmp> Q;
        for(auto i : words) freq[i]++;
        int size = 0;
        for(auto i : freq){
            size++;
            Node cur(i.first,i.second);
            Q.push(cur);
            if(size > k) {
                Q.pop();
                size--;
            }
        }
        stack<string> tmp;
        vector<string> res;
        while(!Q.empty()) tmp.push((Q.top()).word),Q.pop();
        while(!tmp.empty()) res.push_back(tmp.top()),tmp.pop();
        
        return res;
        
    }
};
