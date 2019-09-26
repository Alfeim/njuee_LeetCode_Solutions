/********************************************
作者:Alfeim
题目:在线选举
时间消耗:396ms
解题思路:哈希表
********************************************/
class TopVotedCandidate {
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        int n = persons.size();
        unordered_map<int,int> counts;
        int tmpMax = 0;
        for(int i = 0 ; i < n ; ++i){
            counts[persons[i]]++;
            if(counts[persons[i]] >= tmpMax){
                tmpMax = counts[persons[i]];
                record[times[i]] = persons[i];
            }
        }
    }
    
    int q(int t) {
        auto it = record.lower_bound(t);
        if(it->first == t) return it->second;
        it--;
        return it->second;
    }
    
    map<int,int> record;
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */
