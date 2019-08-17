/********************************************
作者:Alfeim
题目:构造矩形
时间消耗:4ms
解题思路:从平方根开始向下遍历即可
********************************************/
class Solution {
public:
    vector<int> constructRectangle(int area) {
        int border = sqrt(area);
        
        for(int width = border; width > 0 ; --width){
            if(area % width == 0) return {area/width,width};
        }
        
        return {0,0};
        
    }
};
