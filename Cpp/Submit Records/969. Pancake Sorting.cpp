/********************************************
作者:Alfeim
题目:煎饼排序
时间消耗:8ms
解题思路:每次让当前最大数归位即可
********************************************/
class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
        vector<int> res;
        int n = A.size();
        for(int i = n - 1 ; i > 0 ; --i){
            
            int tmpMax = 0;
            int MaxPos = 0;
            
            for(int j = 0 ; j <= i ; ++j){ 
                if(A[j] > tmpMax){
                    tmpMax = A[j];
                    MaxPos = j;
                }              
            }
            
            if(MaxPos == i) continue;
            
            if(MaxPos > 0){
                reverse(A.begin(),A.begin() + MaxPos + 1);
                res.push_back(MaxPos + 1);
            }
            
            reverse(A.begin(),A.begin() + i + 1);
            res.push_back(i + 1);
        }
          
        return res;
    }
};
