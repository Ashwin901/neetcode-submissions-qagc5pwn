class Twitter {
public:
    unordered_map<int, vector<pair<int,int>>> userTweets;
    unordered_map<int, unordered_set<int>> following;
    int time;
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        userTweets[userId].push_back({time++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        unordered_set<int> userF = following[userId];
        userF.insert(userId);
         for(int f : userF){
            for(int i = 0;i<userTweets[f].size();i++){
                pair<int, int> curr = userTweets[f][i];
                if(minHeap.size() < 10){
                    minHeap.push({curr});
                } else {
                    pair<int, int> top = minHeap.top();
                    if(curr.first > top.first){
                        minHeap.pop();
                        minHeap.push(curr);
                    }
                }
            }
         }

         while(!minHeap.empty()){
            pair<int, int> tweet = minHeap.top();
            minHeap.pop();
            res.push_back(tweet.second);
         }

         reverse(res.begin(), res.end());

         return res;

    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            following[followerId].erase(followeeId);
        }
    }
};