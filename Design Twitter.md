## Problem statement
- Design a simplified version of Twitter where users can post tweets, follow/unfollow another user, and is able to see the 10 most recent tweets in the user's news feed.
- Implement the Twitter class:
  1. Twitter() Initializes your twitter object.
  2. void postTweet(int userId, int tweetId) Composes a new tweet with ID tweetId by the user userId. Each call to this function will be made with a unique tweetId.
  3. List<Integer> getNewsFeed(int userId) Retrieves the 10 most recent tweet IDs in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user themself. Tweets must be ordered from most recent to least recent.
  4. void follow(int followerId, int followeeId) The user with ID followerId started following the user with ID followeeId.
  5. void unfollow(int followerId, int followeeId) The user with ID followerId started unfollowing the user with ID followeeId

### Solution
```cpp
class Twitter {
public:
    unordered_map<int, vector<pair<int, int>>> tweets;
    unordered_map<int, unordered_set<int>> followList;
    int time;
    Twitter() { time = 0; }

    void postTweet(int userId, int tweetId) {

        tweets[userId].push_back({time, tweetId});
        time++;
    }

    vector<int> getNewsFeed(int userId) {

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            q;
        for (auto it : tweets[userId]) {
            q.push(it);
            if (q.size() > 10) {
                q.pop();
            }
        }

        for (auto v : followList[userId]) {
            for (auto it : tweets[v]) {
                q.push(it);
                if (q.size() > 10) {
                    q.pop();
                }
            }
        }
        vector<int> res;
        while (!q.empty()) {
            res.push_back(q.top().second);
            q.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }

    void follow(int followerId, int followeeId) {
        followList[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {

        followList[followerId].erase(followeeId);
    }
};
```
- Time complexity: O(F*T*log10)
- Space complexity: O(U*T+U*F)

- ### Optimal (k-way merge)
