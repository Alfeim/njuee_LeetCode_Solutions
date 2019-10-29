/********************************************
作者:Alfeim
题目:K个不同整数的子数组
时间消耗:144ms
解题思路:

维护两个滑动窗口 一个存储有K个数的窗口 一个存储有K-1个数的窗口

假设窗口1的范围是[left1,right] 窗口2的范围是[left2,right]

那么显然，以[left,left)中的所有数为开头的并以Right结尾的子数组中均含有K个不同的数 所以让记录加上 left2 - left1即可
********************************************/
class myWindow{
public:
    myWindow():number_count(0){

    };

    void push(int val){
        count[val]++;
        if(count[val] == 1) number_count++;    
    }

    void erase(int val){
        count[val]--;
        if(count[val] == 0) number_count--;
    }

    int get_number_count(){
        return number_count;
    }

private:
    int number_count;
    unordered_map<int,int> count;
};


class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
       myWindow w1{};
       myWindow w2{};
       int res = 0,left1 = 0,left2 = 0,right = 0,n = A.size();
       while(right < n){
           int cur = A[right];
           w1.push(cur);
           w2.push(cur);
           while(w1.get_number_count() > K){
               w1.erase(A[left1++]);
           }
           while(w2.get_number_count() >= K){
               w2.erase(A[left2++]);
           }

           res += left2 - left1;
           right++;
       }
       return res;
        

    }
};
