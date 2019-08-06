/********************************************
作者:Alfeim
题目:在圆内随机生成点
时间消耗:332ms
解题思路:拒绝采样
********************************************/
class Solution {
public:
    Solution(double radius, double x_center, double y_center):R(radius),XCenter(x_center),YCenter(y_center) {
        
    }
    
    vector<double> randPoint() {
        while(1){
            double x = (double)rand()/RAND_MAX * 2 *R - R;
            double y = (double)rand()/RAND_MAX * 2 *R - R;
            
            double tmp = x*x + y*y;
            if(R*R - tmp > 0.0000001)
                return {XCenter + x ,YCenter + y};
       }
        return {};
    }
    
private:
    double R;
    double XCenter;
    double YCenter;
    
};
