/********************************************
作者:Alfeim
题目:设计推特
时间消耗:302ms
解题思路:设计类问题
********************************************/
class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter() {
        
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        records.push_front(make_pair(userId,tweetId));
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        int n = 0;
        vector<int> res;
        for(int i = 0 ; i < records.size() && n < 10;++i){
            int UID = records[i].first;
            int TID = records[i].second;
            if(UID == userId || follow_record[userId].count(UID) > 0){
                res.push_back(TID);
                n++;
            }
        }
        return res;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        follow_record[followerId].insert(followeeId);
        
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        follow_record[followerId].erase(followeeId);
    }

private:
    deque<pair<int,int>> records;
    unordered_map<int,set<int>> follow_record;
};
