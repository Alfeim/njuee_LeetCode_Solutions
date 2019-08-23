/********************************************
作者:Alfeim
题目:DOTA2参议院
时间消耗:12ms
解题思路:贪心算法
********************************************/
class Solution {
public:
    string predictPartyVictory(string senate) {
        string tmp;
        int countR = 0;
        int countD = 0;
        int n = senate.size();
        for(int i = 0 ; i < n ; ++i){
            tmp += senate[i];
            countR += senate[i] == 'R' ? 1 : 0;
            countD += senate[i] == 'D' ? 1 : 0;
        }
        if(countD == 0) return "Radiant";
        if(countR == 0) return "Dire";
        
        int deleteR = 0;
        int deleteD = 0;
        
        while(!tmp.empty()){
            int n = tmp.size();
            string left;
            for(int i = 0 ; i < n ; ++i){
                if(tmp[i] == 'R'){
                    if(deleteR > 0){
                        deleteR--;
                        countR--;
                        if(countR == 0 ) return "Dire";
                        continue;
                    }else{
                        deleteD++;
                        left += 'R';
                    }
                }else{
                    if(deleteD > 0){
                        deleteD--;
                        countD--;
                        if(countD == 0) return "Radiant";
                        continue;
                    }else{
                        deleteR++;
                        left += 'D';
                    }
                }
            }
            
            tmp = left;
                        
        }
        
        return "Radiant";
    }
};
