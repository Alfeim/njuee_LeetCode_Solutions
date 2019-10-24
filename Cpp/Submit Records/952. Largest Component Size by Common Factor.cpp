/********************************************
作者:Alfeim
题目:按公因数计算最大组件大小
时间消耗:168ms
解题思路:
1.所有具有公因数的两个数间，一定包含有公共质因数
2.通过埃氏筛标记所有可能的质因子，通过并查集的方式将这些数“关联”起来即可
********************************************/
class DSU{
public:
    DSU(int _len):len(_len),childs(len,1),maxChild(len > 0 ? 1 : 0){
        for(int i = 0 ; i < _len ; ++i) parent.push_back(i);
    }

    int getAncestor(int x){
        if(parent[x] != x) parent[x] = getAncestor(parent[x]);
        return parent[x];
    }

    void Union(int x,int y){
        int _x = getAncestor(x);
        int _y = getAncestor(y);

        if(_x == _y) return;

        if(childs[_x] > childs[_y]){
            childs[_x] += childs[_y];
            parent[_y] = _x;
            maxChild = max(childs[_x],maxChild);
            return;
        }

        childs[_y] += childs[_x];
        maxChild = max(childs[_y],maxChild);
        parent[_x] = _y;
        return;
    }

    int getMaxchild(){
        return maxChild;
    }

private:
    int len;
    int maxChild;
    vector<int> parent;
    vector<int> childs;
};

class Solution {
public:
    int largestComponentSize(vector<int>& A){
        int n =  A.size();
        int border = -1;
        //rawpos记录某个数在原数组中的下标
        vector<int> rawpos(100005,-1);
        //visited记录某个数是否访问过，所有被访问过或者非质数的数都将被标记为true
        vector<bool> visited(100005,false);
        for(int i = 0 ; i < n ; ++i){
            rawpos[A[i]] = i;
            border = max(border,A[i]);
        }

        DSU SET(n);
        for(int i = 2 ; i <= border ; ++i){
            if(!visited[i]){
                int curpos = rawpos[i];
                for(int j = i  +  i; j <= border ; j += i){
                    if(rawpos[j] >= 0){
                        if(curpos < 0) curpos = rawpos[j];
                        else SET.Union(curpos,rawpos[j]);
                    }
                    visited[j] = true;
                }
            }
        }

        return SET.getMaxchild();
    }
};
