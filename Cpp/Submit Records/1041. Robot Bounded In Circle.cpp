/********************************************
作者:Alfeim
题目:困于环中的机器人
时间消耗:0ms
解题思路:

只需要遍历一遍:

如果遍历一个周期后,X方向的偏移量与Y方向的偏移量均为0 则一定循环

或者 如果最后面对方向非北 最后也一定循环

********************************************/
class Solution {
public:

    bool isRobotBounded(string instructions) {
        
        int face = 0;
        int G1 = 0,G2 = 0;
        
        for(auto i : instructions){
            if(i == 'G') {
                if(face == 0) G1++;
                else if(face == 2) G1--;
                else if(face == 1) G2++;
                else G2--;
            }else if(i == 'R') 
                face = (face - 1 + 4)%4;
            else 
                face = (face + 1)%4;
        }
        
        return (G1 == 0 && G2 == 0) ||  face != 0;
        
    } 
    
};
