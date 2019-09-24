/********************************************
作者:Alfeim
题目:救生艇
时间消耗:198ms
解题思路:排序、双指针

每次先把重的添加到艇上 然后再决定可否携带一个轻的
********************************************/

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int n = people.size(),res = 0;
        for(int i = 0 , j = n - 1 ; i <= j ;){
            if(people[i] + people[j] <= limit) ++i;
            j--;
            res++;
        }
        
        return res;
    }
};


