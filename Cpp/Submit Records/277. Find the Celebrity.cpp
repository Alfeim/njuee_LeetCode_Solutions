作者:Alfeim
题目:搜寻名人
时间消耗:88ms
解题思路:双指针
用left和right标记名人可能的范围

如果knows(left,right)为真 说明left一定不是名人 故left++

反之，说明right没有倍所有人认识，故right--

最后，检查当前的left是否满足条件，不满足就返回-1
********************************************/
// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        int left = 0,right = n - 1;
        while(left < right){
            if(knows(left,right)) left++;
            else right--;
        }
        
        for(int i = 0 ; i < n ; ++i){
            if(i == left) continue;
            if(!knows(i,left) || knows(left,i)) return -1;            
        }
        
        return left;
    }
};
