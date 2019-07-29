/********************************************
作者:Alfeim
题目:接雨水2
时间消耗:88ms
解题思路:BFS,用一个小顶堆存储每一个节点(初始状态
填入所有最外围的节点),每次从堆顶弹出一个节点元素,
然后遍历其上下左右方位,遇到高度比其小的就累加积水
量,并更新那个高度比本节点的节点高 为 本节点的高度.
直到堆为空
********************************************/
class Solution {
public:
    struct Node{
        int x;
        int y;
        int h;
        Node(int xvalue,int yvalue,int hvalue):x(xvalue),y(yvalue),h(hvalue){};
    };
    
    struct cmp{
        bool operator()(Node& n1,Node&n2){
            return n1.h > n2.h;
        }
    };
    
    priority_queue<Node,vector<Node>,cmp> Q;
    
    int trapRainWater(vector<vector<int>>& heightMap) {
        if(heightMap.empty())
            return 0;
        
        int m = heightMap.size();
        int n = heightMap[0].size();
        if( m < 3 || n < 3)
            return 0;
        
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        
        for(int i = 0 ; i < m ; ++i){
                visited[i][0] = true;
                Q.push(Node(i,0,heightMap[i][0]));
                visited[i][n-1] = true;
                Q.push(Node(i,n-1,heightMap[i][n-1]));
        }
        
        for(int j = 1 ; j < n - 1 ; ++j){
                visited[0][j] = true;
                Q.push(Node(0,j,heightMap[0][j]));
                visited[m-1][j] = true;
                Q.push(Node(m-1,j,heightMap[m-1][j]));
        }
        
        vector<vector<int>> pos({{0,1},{0,-1},{1,0},{-1,0}});
        int res = 0;
        
        while(!Q.empty()){
            int x = Q.top().x;
            int y = Q.top().y;
            int h = Q.top().h;
            Q.pop();
            for(auto i : pos){
                int newx = x + i[0];
                int newy = y + i[1];
                if(newx < 0 || newx >= m || newy < 0 || newy >= n || visited[newx][newy])
                    continue;
                if(h > heightMap[newx][newy]){
                    res += h - heightMap[newx][newy];
                    heightMap[newx][newy] = h;
                }
                Q.push(Node(newx,newy,heightMap[newx][newy]));
                visited[newx][newy] = true;
                
            }
        }
        
        return res;

    }
    
   
    
    
};
