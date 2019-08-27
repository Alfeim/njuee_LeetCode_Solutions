/********************************************
作者:Alfeim
题目:优美的排列2
时间消耗:60ms
解题思路:首先用两个指针分别指向头、尾两个元素 之后开始交替填入头、尾元素(填入后对应指针移动) 
当满足填入k个数后,只需要请按照升序或者降序(取决于最后填入的是左指针还是右指针对应的数)填充其他数即可
********************************************/
class Solution {
public:
    vector<int> constructArray(int n, int k) {
        int left = 1;
        int right = n;
        vector<int> res;
        
        bool flag = true;
        for(int i = 0 ; i < k ; ++i){
            if(flag) res.push_back(left++);
            else res.push_back(right--);
            flag = !flag;
        }
        
        if(!flag){
            while(left <= right) res.push_back(left++);
        }else
            while(left <= right) res.push_back(right--);
        
        return res;
        
        
    }
};
