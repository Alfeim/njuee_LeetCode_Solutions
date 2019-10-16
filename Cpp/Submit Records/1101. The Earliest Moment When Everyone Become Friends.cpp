/********************************************
作者:Alfeim
题目:彼此熟识的最早时间
时间消耗:12ms
解题思路:排序 并查集

维护DSU结构 顺序遍历数组
如果数组内的两个元素没有共同祖先,意味着两个分组可以形成新的一条边 让有效边数+1、
最后如果有效边数 = 人数 - 1说明所有人都在一个集合内 返回对应的时间即可
********************************************/
//DSU结构与定义
class dsu{
public:
    dsu(int val):len(val){
        for(int i = 0 ; i < len ; ++i) {
            parent.push_back(i);
            childs.push_back(1);
        }
    };
    
    ~dsu(){
        
    };
    
    int Ancestors(int &x){
        if(x != parent[x]) parent[x] = Ancestors(parent[x]);
        return parent[x];
    }
    
    void merge(int &x,int &y){
        
        int _x = Ancestors(x);
        int _y = Ancestors(y);
        
        if(_x == _y) return;
        
        if(childs[_x] >= childs[_y]) {
            parent[_y] = _x;
            childs[_x] += childs[_y];
        }
        else{
            parent[_x] = _y;
            childs[_y] += childs[_x];
        }
        
        return;
    }
        
private:
    int len;
    vector<int> parent;   //parents存储节点的祖先
    vector<int> childs;   //childs存储节点子树的元素个数,用于降低时间复杂度
     
};



class Solution {
public:

    
    struct cmp{
        bool operator()(const vector<int> &v1, const vector<int> &v2) const{
            return v1[0] < v2[0];
        } 
    };
    
    int earliestAcq(vector<vector<int>>& logs, int N) {
        sort(logs.begin(),logs.end(),cmp());
        unordered_map<int,unordered_set<int>> graph;
        int EdgeCnt = 0;
        
        dsu SET(N);
        
        for(auto i : logs){
            
            if(SET.Ancestors(i[1]) != SET.Ancestors(i[2])){
                EdgeCnt++;
                SET.merge(i[1],i[2]);
            }
            
            if(EdgeCnt == N-1) return i[0];    
        }
        
        return -1;
    }
};
