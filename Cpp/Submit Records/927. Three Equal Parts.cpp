/********************************************
作者:Alfeim
题目:三等分
时间消耗:56ms
解题思路:
三等分的要求是
1.包含相同的1的个数---据此可以预先划分出每个区段的“起止位置”
2.末尾的0个数相同---因此只需要从末尾开始统计每个区间最后有多少0
3.用第一次划分的区间，加上末尾的0的个数，也就是真正划分的区间
4.比较各个区间是否相等即可
********************************************/
class Solution {
public:
    vector<int> threeEqualParts(vector<int>& A) {
        
        //所谓三等分 应当保证三个部分的1个数相等

        string str;
        int n = A.size();
        
        int count_one = 0;
        
        for(auto i : A) {
            count_one += i;
            str.push_back('0' + i);
        }
        
        if(count_one % 3 != 0) return {-1,-1};
        
        if(count_one == 0) return {0,n-1};
        
        int target_count = count_one / 3;
        int second_begin = 0;
        int third_begin = 0;
        
       
        for(int i = 0,tmp_count = 0; i < n ; ++i){
            tmp_count += A[i];
            if(second_begin == 0 && tmp_count == target_count) second_begin = i + 1;
            if(third_begin == 0 && tmp_count == 2 * target_count) third_begin = i + 1;
        }

        //计算末尾0的个数
        int count_zero = 0;
        for(int i = n - 1 ; i >= 0 && A[i] == 0 ; i--) count_zero++;
        
        string part1 = str.substr(0,second_begin + count_zero);
        string part2 = str.substr(second_begin,third_begin - second_begin + count_zero);
        string part3 = str.substr(third_begin);
        
        if(isSame(part1,part2) && isSame(part2,part3)) return {second_begin + count_zero - 1 ,third_begin + count_zero};
        
        return {-1,-1};
        
    }
    
      bool isSame(string str1,string str2){
        int pos1 = 0,pos2 = 0;
        int m = str1.size(),n = str2.size();
        
        while(pos1 < m && str1[pos1] != '1') pos1++;
        while(pos2 < n && str2[pos2] != '1') pos2++;
        
        str1 = str1.substr(pos1);
        str2 = str2.substr(pos2);
        
        return str1 == str2;
    }



};
