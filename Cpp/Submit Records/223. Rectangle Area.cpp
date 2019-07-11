/********************************************
作者:Alfeim
题目:矩形面积
时间消耗:8ms
解题思路:细节题
********************************************/
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {       
        int Width;
        int Height;
        long res = 0; 
        int Area1 = (D-B)*(C-A);
        int Area2 = (G-E)*(H-F);
        
        //不重叠的情况
        if( C <= E || A >= G || B >= H || D <= F){
            res = (long)Area1 + (long)Area2;
            return res;
        }   
        //重叠的情况
        if(A <= E){
            Width = min(abs(C-E),abs(G-E));
        }else{
            Width = min(abs(C-A),abs(G-A));
        }

        if(B <= F){
            Height = min(abs(H-F),abs(D-F));
        }else{
            Height = min(abs(D-B),abs(H-B));
        }
        
        int Area3 = Height * Width;
        res = (long)Area1 + (long)Area2 - (long)Area3;
        return res;
    }
};
