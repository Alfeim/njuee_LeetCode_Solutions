/********************************************
作者:Alfeim
题目:交叉路径
时间消耗:8ms
解题思路:细节实现
********************************************/
class Solution {
public:
    bool isSelfCrossing(vector<int>& x) {
        int n = x.size();
        if(n < 4)
            return false;
        
        int last1 = 0;
        int last2 = 0;  
        
        for(int i = 0 ; i < n ; ++i){
            if(i % 2 == 0){
                if( x[i] <= last1 && i + 1 < n  && isCrossed(x,i) ) return true;
                last1 = x[i];
            }else if(i % 2 == 1){
                if( x[i] <= last2 && i + 1 < n  && isCrossed(x,i) ) return true;
                last2 = x[i];
            }
        }
        
        return false;  
    }
    
    bool isCrossed(vector<int> &x,int i){
        if(i < 3)
            return x[i + 1] >= x[i-1];
        
        else if(i == 3)
            return ( x[i] == x[i-2] && x[i - 1] + x[i + 1] >= x[i-3] ) || (x[i] < x[i-2] && x[i+1] >= x[i-1]);
        
        
        if( x[i-1] <= x[i - 3])
            return x[i + 1] >= x[i-1];
            
        return  ( x[i] + x[i-4] >= x[i-2]  && x[i + 1 ] + x[i-3] >= x[i-1] ) || ( x[i] + x[i-4] < x[i-2] && x[i + 1] >= x[i-1] ) ;
    }
};
