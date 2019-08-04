/********************************************
作者:Alfeim
题目:我能赢吗
时间消耗:144ms
解题思路:记忆化搜索,用bit存储每一个对应的状态
********************************************/
class Solution {
public:
    unordered_map<int,bool> record;
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        int sum = (1 + maxChoosableInteger)*maxChoosableInteger/2;
        if(maxChoosableInteger >= desiredTotal)
            return true;
        if(sum < desiredTotal) 
            return false;
        if(sum == desiredTotal) 
            return maxChoosableInteger%2 != 0;
        
        return Solve(maxChoosableInteger,desiredTotal,0);
    }
    
    
    bool Solve(int maxChoose,int target,int used){
        if(record.count(used) > 0)
            return record[used];
        
        for(int i = 0 ; i < maxChoose ; ++i){
            int tmp = (1 << i);
            if( (used & tmp) == 0){
                if(target <= i + 1 || !Solve(maxChoose,target - i - 1,used | tmp)){
                    record[used] = true;
                    return true;
                }   
            }
        }
        record[used] = false;
        return false;
    }
    
};
