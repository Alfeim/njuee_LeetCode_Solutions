/********************************************
作者:Alfeim
题目:在LR字符串中交换相邻字符串
时间消耗:4ms
解题思路:
思路分析： 题目的意思是说 ‘R’只能向右移动，并且只能移向’X’，‘L’只能向左移动，并且只能移向’X’。

第一：如果将start、end中的‘X’全部去掉得到的newStart 和 newEnd相等才有可能转换成功。
第二：如果start中'R'的左边'X'的个数超过在end中对应位置的的左边'X'的个数，则不能转换成功，因为start中的'R'只能向右移动，右边的'X'只能增加不能减少
第三：如果start中'L'的左边'X'的个数小于在end中对应位置的左边'X'的个数，则不能转换成功，因为start中的'L'只能向左移动，左边的'X'只能减少不能增加
********************************************/
class Solution {
public:
    bool canTransform(string start, string end) {
        int m = start.size(),n = end.size();
        if(m != n) return false;
        
        for(int i = 0,j = 0 ; i < m && j < n ;++i,++j){
            while(i < m && start[i] == 'X') ++i;
            while(j < n && end[j] == 'X') ++j;
            if( start[i] != end[j]) return false; 
            if( (start[i] == 'L' && i < j )  || ( start[i] == 'R'  && i > j ) ) return false;
            
        }
        return true;

    }
};
