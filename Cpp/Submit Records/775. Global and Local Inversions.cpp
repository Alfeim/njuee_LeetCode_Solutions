/********************************************
作者:Alfeim
题目:全局倒置与局部倒置
时间消耗:300ms
解题思路:
1.逆序对
2.观察,如果要让全局倒置等于局部倒置意味着必须全为局部倒置
这样,当前位置的数就不能比其后第二位的数大,也就是说一旦出现
A[i] > A[i+2]即为false
********************************************/

//逆序对解法
class Solution {
public:
    int All;
    bool isIdealPermutation(vector<int>& A) {
        int n = A.size(),local = 0;
        All = 0;
        for(int i = 0 ; i < n - 1 ; ++i){
            local += (A[i] > A[i+1]) ? 1 : 0;
        }

        Solve(0,n-1,A);
        return local == All;
    }
    
    
    //即求逆序对,实际上也就是归并排序的基础上稍微修改(分治法)
    vector<int> Solve(int begin,int end,vector<int>& A){
        int mid = (begin + end + 1)/2;
        
        //边界条件
        if(begin >= end) return {A[mid]};
        
        //递归求解
        vector<int> tmp;
        auto left = Solve(begin,mid - 1,A);
        auto right = Solve(mid,end,A);
        int m = left.size(),n = right.size();
        
        int i = 0 , j = 0;
        while(i < m && j < n){
            if(left[i] < right[j]){  
                All += j;
                tmp.push_back(left[i++]);
            }else{
                tmp.push_back(right[j++]);
            }    
        }
        
      
        if(i < m){
            while(i < m) tmp.push_back(left[i++]),All += n;
        }
        
        if(j < n){
            while(j < n) tmp.push_back(right[j++]);
        }
        
        
        return tmp;
    }
    
    
};


//观察法
        int len = A.length;
        if (len <= 2) {
            return true;
        }
        int max = A[0];
        for (int i = 2; i < len; i ++) {
            if (max > A[i]) {
                return false;
            }
            if (max < A[i - 1]) {
                max = A[i - 1];
            }
        }
        return true;

