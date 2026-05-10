## Problem statement
- You are given a string array events.
- Initially, score = 0 and counter = 0. Each element in events is one of the following:
  - "0", "1", "2", "3", "4", "6": Add that value to the total score.
  - "W": Increase the counter by 1. No score is added.
  - "WD": Add 1 to the total score.
  - "NB": Add 1 to the total score.
- Process the array from left to right. Stop processing when either:
  - All elements in events have been processed, or
  - The counter becomes 10.
- Return an integer array [score, counter], where:
  - score is the final total score.
  - counter is the final counter value.
 
## Solution
```cpp
class Solution {
public:
    vector<int> scoreValidator(vector<string>& events) {

        int n = events.size();
        int score = 0;
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (count == 10) {
                break;
            }
            if (events[i] == "W") {
                count++;
            } else if (events[i] == "WD" || events[i] == "NB") {
                score++;
            } else {
                score += stoi(events[i]);
            }
        }
        return {score, count};
    }
};
```
- Time complexity: O(n)
- Space complexity: O(1)
