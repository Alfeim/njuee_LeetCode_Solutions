/********************************************
作者:Alfeim
题目:分发糖果
时间消耗:32ms
解题思路:用两个数组before和after分别记录到当前位置之前的递增序
列的长度，和当前位置后的递减序列长度。那么，最后，每个位置应发的
糖数目，等于递增和递减序列中长度最大者。
********************************************/
int candy(vector<int>& ratings) {
        vector<int> less_before(ratings.size(),0);
        vector<int> less_after(ratings.size(),0);
        less_before[0] = 1;
        less_after[ratings.size()-1] = 1;
        int sum = 0;
        
        for(int i = 1 ; i < ratings.size();++i)
            less_before[i] = ratings[i] > ratings[i-1] ? 1 + less_before[i-1] : 1 ;
        
        for(int j = ratings.size() - 2 ; j >= 0 ; --j)
            less_after[j] = ratings[j] > ratings[j+1] ? 1 + less_after[j+1] : 1;
        
        
        for(int k = 0 ; k < ratings.size();++k){
            sum += max(less_before[k],less_after[k]);
        }
        
        return sum;

    }
    
};
