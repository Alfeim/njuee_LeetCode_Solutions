/********************************************
作者:Alfeim
题目:IPO
时间消耗:60ms
解题思路:贪心
********************************************/
class Solution {
public:
    struct cmp{
        bool operator()(const pair<int,int> &p1,const pair<int,int> &p2) const{
            return p1.first > p2.first;
        }
    };
    
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        list<pair<int,int>> LIST;
        int n = Profits.size();
        for(int i = 0 ; i < n ; ++i){
            LIST.push_back(make_pair(Profits[i],Capital[i]));
        }
        
        LIST.sort(cmp());
        int sum = W;
        while(k && !LIST.empty()){
            auto it = LIST.begin();
            while(it != LIST.end()){
                if(it->second <= sum){
                    sum += it->first;
                    LIST.erase(it);
                    k--;
                    break;
                }
                it++;
            }
            if(it == LIST.end()) break;
        }
        
        return sum;
    }
};
