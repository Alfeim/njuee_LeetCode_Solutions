/********************************************
作者:Alfeim
题目:猫和老鼠
时间消耗:108ms
解题思路:BFS
相似题目：
参考:https://leetcode-cn.com/problems/cat-and-mouse/solution/bu-liao-jie-ji-da-ji-xiao-suan-fa-ke-yi-tong-guo-b/

假设status是一个三维矩阵，表示状态转移。这里按照所有可能情况给出基本情况判断：

status[i][j][0]表示鼠在节点i，猫在节点j，且此时轮到鼠行动的状态；
status[i][j][1]表示鼠在节点i，猫在节点j，且此时轮到猫行动的状态；
status[i][j][k]如果值为0，表示默认值，平局；
如果status[i][j][k]值为1表示鼠胜；如果值为2表示猫胜
由规则可知，初始状态下可以确定的非平局状态有：

status[0][j][k] = 1；此刻鼠在洞里，必胜
status[i][i][k] = 2, i~=0；此刻猫鼠同位，猫必胜
status[i][1][k]不能被访问。
由最终状态倒推之前的可能性：

对于节点status[i][j][0]来说，此时轮到鼠行动，上一步轮到猫行动：
1.1 如果status[i][j][0]=1，即此步鼠胜。则对于能一步到达该状态的每一个可能的上一步状态status[i][graph[j]][1]来说，如果该“上一步状态”的所有下一步状态（包括status[i][j][0]）都是鼠胜，则该“上一步状态”一定是鼠胜。
1.2 如果status[i][j][0]=2，即此步猫胜。则由于上一步轮到猫行动，鼠不能动，所以对于能一步到达该状态的所有可能的上一步状态status[i][graph[j]][1]都为2，即上一步猫已经完全锁定胜局。
1.3 如果status[i][j][0]=0，即此步未知（平局），则无法对上一步状态进行判断。
对于节点status[i][j][1]来说，此时轮到猫行动，上一步轮到鼠行动：
2.1 如果status[i][j][1]=1，即此步鼠胜。由于上一步轮到鼠行动，所以对于能一步到达该状态的所有可能的上一步状态status[graph[i]][j][0]来说，值都为1，即上一步鼠已经完全锁定胜局。
2.2 如果status[i][j][1]=2，即此步猫胜。则对于能一步到达该状态的每一个可能的上一步状态status[graph[i]][j][0]来说，如果该“上一步状态”的所有下一步状态（包括status[i][j][1]）都是猫胜，则该“上一步状态”一定是猫胜。
2.3 如果status[i][j][1]=0，即此步未知（平局），则无法对上一步状态进行判断。
因此，可以设置一队列，将所有非平局状态全部塞入，然后遍历每个队列元素，如果根据该元素能够判断其上一步状态的胜负，则将其上一步状态推入队列。如此循环往复，直到队列为空为止。



********************************************/
class Solution {
public:
    struct node{
        int i;
        int j;
        int k;
        int val;
        node(int _mpos,int _cpos,int _k,int _val):i(_mpos),j(_cpos),k(_k),val(_val){};
    };
    
    queue<node*> Q;
    
    int catMouseGame(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<vector<int>>> status(n,vector<vector<int>>(n,vector<int>(2,0)));
        Initialize(n,status);
        Solve(status,graph);
        return status[1][2][0];
    }
    
    void Solve(vector<vector<vector<int>>> &status,vector<vector<int>>& graph){
        
        while(!Q.empty()){
            auto cur = Q.front();
            Q.pop();
            
            if(cur->k == 0){
            //老鼠行动
                if(cur->val == 1){ //如果此时老鼠已经获胜
                    for(auto pre : graph[cur->j]){ //遍历此时猫状态可能的上一状态
                        bool MouseWin = true;
                        for(auto preNext : graph[pre]){
                            if(preNext != 0 && status[cur->i][preNext][0] != 1){
                                MouseWin = false;
                                break;
                            }
                        }
                        //上一步情况下也为鼠胜
                        if(MouseWin && status[cur->i][pre][1] == 0 && pre != 0){
                            status[cur->i][pre][1] = 1;
                            Q.push(new node(cur->i,pre,1,1));
                        }
                        
                    }
                }else{//如果此步猫胜
                    for(auto pre : graph[cur->j]){
                        if(pre != 0 && status[cur->i][pre][1] == 0){
                            status[cur->i][pre][1] = 2;
                            Q.push(new node(cur->i,pre,1,2));   
                        }
                    }
                 }
            }else{
            //猫行动
                if(cur->val == 2){//如果此时猫胜利
                    for(auto pre : graph[cur->i]){
                        bool CatWin = true;
                        for(auto preNext : graph[pre]){
                            if(cur->j != 0 && status[preNext][cur->j][1] != 2){
                                CatWin = false;
                                break;
                            }
                        }
                        
                        if(CatWin && status[pre][cur->j][0] == 0 && cur->j != 0){
                            status[pre][cur->j][0] = 2;
                            Q.push(new node(pre,cur->j,0,2));
                        }
                    }
                }else{//如果此步鼠胜利
                    for(auto pre : graph[cur->i]){
                        if(cur->j != 0 && status[pre][cur->j][0] == 0){
                            status[pre][cur->j][0] = 1;
                            Q.push(new node(pre,cur->j,0,1));
                        }   
                    }
                }
            }
            
        }
        
    }
    
    
    void Initialize(int n, vector<vector<vector<int>>> &status){
        
        for(int j = 1 ; j < n ; ++j){
            status[0][j][0] = 1;
            status[0][j][1] = 1;
            Q.push(new node(0,j,0,1));
            Q.push(new node(0,j,1,1));
        }
        
        for(int i = 1 ; i < n ; ++i){
            status[i][i][0] = 2;
            status[i][i][1] = 2;
            Q.push(new node(i,i,0,2));
            Q.push(new node(i,i,1,2));
        }
        
        
    }
};
