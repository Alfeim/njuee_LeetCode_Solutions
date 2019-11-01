/********************************************
作者:Alfeim
题目:尽可能使字符串相等
时间消耗:8ms
解题思路:滑动窗口
********************************************/
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = t.size();
        int left = 0,right = -1;
        int cost = 0;
        int res = 0;

        while(left < n && right < n){

            if(right < left ) right = left;
            
            while(right < n && cost <= maxCost){
                cost += abs(t[right] - s[right]);
                if(cost > maxCost) break;
                right++;
            }

            res = max(res,right - left);

            while(left <= right && cost > maxCost){
                cost -= abs(t[left] - s[left]);
                left++;
            }
            right++;
        }
        return res;

    }
   
};
