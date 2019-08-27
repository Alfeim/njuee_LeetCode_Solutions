/********************************************
作者:Alfeim
题目:最大交换
时间消耗:4ms
解题思路:取得每个元素右边的最大值位置并记录为一个数组right_max; 从头遍历每个元素,
比较当前元素和其对应right_max位置上的元素谁大.如果right_max上的元素更大就交换并退出循环
********************************************/
class Solution {
public:
    int maximumSwap(int num) {
        string str(to_string(num));
        int n = str.size();
        
        vector<int> number;
        for(auto i : str) number.push_back(i - '0');
        
        vector<int> right_max(n,0);
        int tmpMax = number[n-1];
        int tmpPos = n - 1;
        
        for(int i = n - 2 ; i >= 0 ; --i){
            if(number[i + 1] > tmpMax){
                tmpMax = number[i+1];
                tmpPos = i + 1;
            }
            right_max[i] = tmpPos;
        }

        for(int i = 0 ; i < n - 1; ++i){
            if(number[right_max[i]] > number[i]){
                swap(number[i],number[right_max[i]]);
                break;
            }
        }
        
        int res = 0;
        for(auto i : number){
            res *= 10;
            res += i;
        }
        
        return res;
    }
};
