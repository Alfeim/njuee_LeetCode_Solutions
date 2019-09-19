/********************************************
作者:Alfeim
题目:一手顺子
时间消耗:108ms
解题思路:哈希表、排序
********************************************/
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        int n = hand.size();
        if(n == 0 || n % W != 0 ) return false;
        
        unordered_map<int,int> counts;
        for(auto i : hand) counts[i]++;
        sort(hand.begin(),hand.end());
        
   
        for(int i = 0 ; i < n ; ++i){
            if(counts[hand[i]] == 0) continue;
            else{
                for(int j = 0 ; j < W ; ++j){
                    if(counts[hand[i] + j] == 0) return false;
                    counts[hand[i] + j]--;
                }  
            }
        }
        
        return true;
        
    }
};
