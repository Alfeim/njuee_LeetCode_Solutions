/********************************************
作者:Alfeim
题目:滑动谜题
时间消耗:4ms
解题思路:BFS
********************************************/
class Solution {
public:
  
    int slidingPuzzle(vector<vector<int>>& board) {
        unordered_set<string> record;
        queue<string> Q;
        string tmp;
        string target = "123450";
        
        for(int i = 0; i < 6; ++i){
            int col = i < 3 ? i : i - 3;
            int row = i < 3 ? 0 : 1;
            tmp += ('0' + board[row][col]);
        }
        
        if(tmp == target) return 0;
        
        int step = 0;
        Q.push(tmp);
        record.insert(tmp);
        
        while(!Q.empty()){
            int size = Q.size();
            step++;
            
            while(size--){
                auto str = Q.front();
                Q.pop();
                
                int pos = 0;
                for(; pos < 6 ;++pos){
                    if(str[pos] == '0') break;
                }
                
                //与后一位交换
                if( (pos >= 0 && pos <= 1) || (pos >= 3 && pos <= 4)){
                    swap(str[pos],str[pos+1]);
                    if(str == target) return step;
                    if(!record.count(str)){
                        record.insert(str);
                        Q.push(str);
                    } 
                    swap(str[pos],str[pos+1]);
                }
                
                //与前一位交换
                if( (pos >= 1 && pos <= 2) || (pos >= 4 && pos <= 5)){
                    swap(str[pos],str[pos-1]);
                    if(str == target) return step;
                    if(!record.count(str)){
                        record.insert(str);
                        Q.push(str);
                    } 
                    swap(str[pos],str[pos-1]);
                }
                
                
                //与上下交换
                int next = pos < 3 ? 3 : -3;
                swap(str[pos],str[pos+next]);
                if(str == target) return step;
                if(!record.count(str)){
                    record.insert(str);
                    Q.push(str);
                } 
                swap(str[pos],str[pos+next]);
                
            }
            
        }
        
        
        return -1;
        
        
    }
    
};
