/********************************************
作者:Alfeim
题目:螺旋矩阵
时间消耗:40ms
解题思路:细节题..
********************************************/
class Solution {
public:
    int x;
    int y;
    int m;
    int n;
    int sum;
    vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
        x = c0,y = r0,m = R,n = C,sum = 1;
        
        int target = R * C;
        vector<vector<int>> res{};
        vector<int> step{1,1,2,2};

        while(sum <= target){   
            for(int i = 0 ; i < 4 ; ++i){
                if(i == 0){
                    go_right(res,step[0]);
                    step[0] += 2;
                }else if(i == 1){
                    go_down(res,step[1]);
                    step[1] += 2;
                }else if(i == 2){
                    go_left(res,step[2]);
                    step[2] += 2;
                }else if(i == 3){
                    go_up(res,step[3]);
                    step[3] += 2;
                }
            }

        }
        
        return res;
        
    }
    
    void go_right(vector<vector<int>> &res,int target){
        int step = 0;
        int xpos = x;

        while(step < target){
            if(valid(m,n,xpos,y)) {
                res.push_back({y,xpos});
                sum++;
            }
            step++;
            xpos++;
        }
        
        x += target; 
    }
    
    
    void go_left(vector<vector<int>> &res,int target){
        int step = 0;
        int xpos = x;
        while(step < target ){
            if(valid(m,n,xpos,y)){
                res.push_back({y,xpos});
                sum++;
            }
            step++;
            xpos--;
        }
        
        x -= target; 
    }
    
    
    void go_up(vector<vector<int>> &res,int target){
        int step = 0;
        int ypos = y;
          while(step < target){
            if(valid(m,n,x,ypos)) {
                res.push_back({ypos,x});
                sum++;
            }
            step++;
            ypos--;
        }
          
        y -= target; 
    }
    
    
    void go_down(vector<vector<int>> &res,int target){
        int step = 0;
        int ypos = y;
        while(step < target){
            if(valid(m,n,x,ypos)){
                res.push_back({ypos,x});
                sum++;
            }
            step++;
            ypos++;
        }

        y += target; 
    }
    
    bool valid(int &m,int &n,int &col,int &row){
        if(row >= 0 && row < m && col >= 0 && col < n) return true;
        return false;
    }
    
        
};
