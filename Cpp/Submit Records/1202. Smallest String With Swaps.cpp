/********************************************
作者:Alfeim
题目:交换字符串中的元素
时间消耗:212ms
解题思路:并查集，对不同连通分量集合进行排序
********************************************/

class DSU{

public:
    DSU(const int &len):parent(len,0),child(len,1){
        for(int i = 0 ; i < len ; ++i) parent[i] = i;
    }

    int getAncestor(const int &x){
        if(parent[x] != x) parent[x] = getAncestor(parent[x]);
        return parent[x];
    }

    void Union(const int &x,const int &y){
        int _x = getAncestor(x);
        int _y = getAncestor(y);
        
        if(_x == _y) return;
        
        if(child[_x] > child[_y]){ 
            parent[_y] = x;
            child[_x] += child[_y];
            return;
        }

        parent[_x] = _y;
        child[_y] += child[_x];
        return;
    }

private:
    vector<int> parent;
    vector<int> child;
};


class Solution {
public:
    unordered_map<int,vector<int>> M;
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        if( n == 0 ) return "";

        DSU SET(n);

        //初始化
        for(auto i : pairs){
            if(SET.getAncestor(i[0]) != SET.getAncestor(i[1])) SET.Union(i[0],i[1]);
        }
        
        //合并连通分量
        for(int i = 0 ; i < n ; ++i) M[SET.getAncestor(i)].push_back(i);
        
        //遍历
        int pos;
        
        for(auto i : M){
            pos = 0;
            string tmp;
            for(auto p : i.second ) tmp.push_back(s[p]);
            sort(tmp.begin(),tmp.end()); 
            for(auto p : tmp) s[i.second[pos++]] = p;
        }
        
        return s;
    }

};
