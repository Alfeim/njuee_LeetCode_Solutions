/********************************************
作者:Alfeim
题目:分割数组
时间消耗:164ms
解题思路:1.利用map 2.维护双变量
********************************************/
//方法1
class Solution {
public:
    int partitionDisjoint(vector<int>& A) {
        map<int,int> counts;
        for(auto i : A) counts[i]++;
        
        int n = A.size();
        int right = 0;
        int tmpMax = INT_MIN;
        
        while(right < n - 1){
            counts[A[right]]--;        
            tmpMax = max(tmpMax,A[right]);
            
            if(counts[A[right]] == 0){
                counts.erase(A[right]);
            }
            
            if( tmpMax <= (counts.begin())->first) return right + 1; 
            
            right++;
            
        }
        
        return 0;
    
    }
};

//方法2 维护两个变量 当前最大值和左数组最大值
public int partitionDisjoint(int[] A) {
        if (A == null || A.length == 0) {
            return 0;
        }

        int leftMax = A[0];
        int max = A[0];
        int index = 0;

        for (int i = 0; i < A.length; i++) {
            max = Math.max(max, A[i]);
            if(A[i] < leftMax) {
                leftMax = max;
                index = i;
            }
        }

        return index + 1;
    }
