/********************************************
作者:Alfeim
题目:火星词典
时间消耗:ms
解题思路:拓扑排序

最开始的思路是: 根据当前单词和后一个单词,可以构成某些字符的parents---children关系,
通过遍历一遍所有单词后,我们也就获得了所有已知的parent-children关系集合(多对多映射),
那么接下来只要从那些没有parent的节点(源节点)开始层次遍历即可.

但是,调试过程中发现层次遍历的方式其实是有问题的,比如字符 W 和 E都是第一层的源节点,而字符I是E的孩子，
但是I也是W的孩子C的孩子,显然我们需要先遍历完C再遍历I,但是按照层次遍历的话显然I已经先于C被遍历了..

仔细观察后发现,要遍历某个节点,实际上只要等到该节点的所有父节点被遍历后就可以了！

---这个概念是不是十分眼熟-----没错,就是拓扑排序的入度(indegree)啊！如果把所有的parent-child关系看
作有向边，那么这实际就是一道拓扑排序问题啊！
********************************************/
class Solution {
public:
    struct Node{
        vector<Node*> childs;
        char word;
        int indegrees;
        Node(char _word):word(_word),indegrees(0){};
    };
    
    string alienOrder(vector<string>& words) {
        vector<Node*> records(26,nullptr);
        string res;
        
        int Len = words.size();
        int words_count = 0;
   
        for(auto i : words){
            for(auto j : i){
                if(!records[j - 'a']) {
                    words_count++;
                    records[j - 'a'] = new Node(j);
                }
            }
        }
        
        int m = 0,n = 0,pos = 0;
        for(int i = 1 ; i < Len ; ++i){
            pos = 0;
            m = words[i].size();
            n = words[i-1].size();
            
            while(pos < m && pos < n && words[i][pos] == words[i-1][pos]) pos++;
            
            if(pos == m || pos == n) continue;
            
            records[words[i - 1][pos] - 'a']->childs.push_back( records[words[i][pos] - 'a'] );
            records[words[i][pos] - 'a']->indegrees++;
        }
    
        
        queue<Node*> Q;
        for(auto node : records){
            if(node && node->indegrees == 0){
                Q.push(node);
            }
        }
    
        //拓扑排序
        while(!Q.empty()){
            int size = Q.size();
            while(size--){
                auto cur = Q.front();
                Q.pop();
                res += cur->word;
                for(auto c : cur->childs){
                    int number = c->word - 'a';
                    records[number]->indegrees--;
                    
                    if(records[number]->indegrees == 0){
                        Q.push(c);
                    }
                }
                
            }
            
        }
        
        return res.size() == words_count ? res : "";
        
    }
    
    
   

};
