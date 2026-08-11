class Twitter {
private:
    int timestamp;
    vector<vector<pair<int, int>>> tweets;
    vector<unordered_set<int>> followers; 
public:
    Twitter() {
        timestamp = 0;
        tweets.resize(501);
        followers.resize(501);
    }
    
    void postTweet(int userId, int tweetId) {
        timestamp++;
        tweets[userId].push_back({timestamp,tweetId});
        return;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<vector<int>> pq;
        unordered_set<int> follower = followers[userId];
        follower.insert(userId);
        for(int f: follower)
        {
            if(!tweets[f].empty())
            {
                int lastIdx = tweets[f].size()-1;
                pq.push({tweets[f][lastIdx].first,tweets[f][lastIdx].second,f,lastIdx});
            }
        }

        vector<int> result;
        while(!pq.empty() && result.size()<10)
        {
            auto element = pq.top();
            pq.pop();
            int tweet = element[1], fol = element[2], idx = element[3];
            result.push_back(tweet);
            if(idx)
            pq.push({tweets[fol][idx-1].first,tweets[fol][idx-1].second,fol,idx-1});

        }
        return result;
    }
    
    void follow(int followerId, int followeeId) {
        followers[followerId].insert(followeeId);
        return;
    }
    
    void unfollow(int followerId, int followeeId) {
        followers[followerId].erase(followeeId);
        return;
    }
};