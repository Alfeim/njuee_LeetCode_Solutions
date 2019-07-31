/********************************************
作者:Alfeim
题目:第三大的数
时间消耗:8ms
解题思路:两种方法，一种借助set自动排序,另一种
直接用三个变量标记
********************************************/

//利用set自动排序,时间复杂度O(3log3 * n) = O(n);
class Solution {
public:
    int thirdMax(vector<int>& nums) {
       set<int> record;
       for(auto i : nums){
           if(record.size() < 3)
               record.insert(i);
           else if(record.count(i) > 0){
               continue;
           }else{
               auto cur = record.begin();
               if(i > *cur){
                    record.erase(cur);
                    record.insert(i);
               }
           }
       }  
       return record.size() == 3 ? *record.begin() : *record.rbegin();   
    }
};

//空间O(1)做法
class Solution {
public:
    int thirdMax(vector<int>& nums) {
       int count = 0;
       int max1 = INT_MIN,max2 = INT_MIN,max3 =INT_MIN,minval = INT_MAX;
       set<int> record;
       for(auto i : nums){
           if(count == 0){
               max1 = i;
               count++;
           }
           else if(count == 1 && i != max1){
               max2 = i;
               count++;
           }
           else if(count == 2 && i != max1 && i != max2){
               max3 = i;
               count++;
           }
           else{
               if(i == max1 || i == max2 || i == max3)
                   continue;
                minval = min(min(max1,max2),max3);
                if(i > minval){
                    if(minval == max1) 
                        max1 = i;
                    else if(minval == max2) 
                        max2 = i;
                    else 
                        max3 = i;

                }
           }
       }  
    
       return count >= 3 ? min(min(max1,max2),max3) : max(max(max1,max2),max3);   
    }
};
