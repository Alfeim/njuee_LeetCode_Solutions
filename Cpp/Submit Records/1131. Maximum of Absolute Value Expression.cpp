/********************************************
作者:Alfeim
题目:绝对值表达式的最大值
时间消耗:56ms
解题思路:状态转移
********************************************/
class Solution {
public:
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        //一共分为4种情况(默认i > j))
        //1.arr1[i] >= arr1[j],arr2[i] >= arr2[j]  --->  (arr1[i] + arr2[i] + i ) - (arr1[j] + arr2[j] + j)
        //2.arr1[i] >= arr1[j],arr2[i] < arr2[j]   --->  (arr1[i] - arr2[i] + i) - (arr1[j] - arr2[j] + j)
        //3.arr1[i] < arr1[j],arr2[i]  < arr2[j]   --->  -(arr1[i] + arr2[i] - i) + (arr1[j] + arr2[j] - j)
        //4.arr1[i] < arr1[j],arr2[i] >= arr2[j]   --->  -(arr1[i] - arr2[i] - i) + (arr1[j] - arr2[j] - j)

        int res = 0;
        int n = arr1.size();

        vector<int> prev(4,0);

        prev[0] = arr1[0] + arr2[0];
        prev[1] = arr1[0] - arr2[0];
        prev[2] = -(arr1[0] + arr2[0]);
        prev[3] = -(arr1[0] - arr2[0]);

        for(int i = 1 ; i < n ; ++i){
            res = max(res,arr1[i] + arr2[i] + i - prev[0]);prev[0] = min(arr1[i] + arr2[i] + i,prev[0]);
            res = max(res,arr1[i] - arr2[i] + i - prev[1]);prev[1] = min(arr1[i] - arr2[i] + i,prev[1]);
            res = max(res,i - arr1[i] - arr2[i] - prev[2]);prev[2] = min(i - arr1[i] - arr2[i],prev[2]);
            res = max(res,i - arr1[i] + arr2[i] - prev[3]);prev[3] = min(i - arr1[i] + arr2[i],prev[3]);
        }

        return res;

    }
};
