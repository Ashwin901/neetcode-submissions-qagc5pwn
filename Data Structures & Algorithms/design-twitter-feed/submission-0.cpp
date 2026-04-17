class Twitter {
public:
    stack<pair<int, int>> tweets;
    unordered_map<int, unordered_set<int>> following;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets.push({tweetId, userId});
    }
    
    vector<int> getNewsFeed(int userId) {
        unordered_set<int> userF = following[userId];
        vector<int> res;
        stack<pair<int, int>> temp;

        while(res.size() < 10 && !tweets.empty()){
            pair<int, int> t = tweets.top();
            tweets.pop();
            temp.push(t);
            if(t.second == userId || userF.find(t.second) != userF.end()) res.push_back(t.first);
        }

        while(!temp.empty()){
            pair<int, int> t = temp.top(); temp.pop();
            tweets.push(t);
        }

        // reverse(res.begin(), res.end());

        return res;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};
