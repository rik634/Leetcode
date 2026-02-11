## Problem statement
- There is one meeting room in a firm. You are given two arrays, start and end each of size N. For an index ‘i’, start[i] denotes the starting time of the ith meeting while end[i] will denote the ending time of the ith meeting.
- Find the maximum number of meetings that can be accommodated if only one meeting can happen in the room at a particular time. Print the order in which these meetings will be performed.

### Logic
- We need to schedule as many meetings as possible in a single room without overlaps. The key observation is that once we choose a meeting that ends earliest, it leaves the room available for more potential meetings afterward.
- This naturally leads to a greedy approach, where instead of testing all possible combinations we pick meetings in an order that maximizes free time for future meetings.
- The greedy choice is to always select the meeting that finishes earliest among the available ones.

### Solution
```cpp
class Solution {
public:
    // Function to get all meetings that can be scheduled
    vector<int> maxMeetings(vector<int>& start, vector<int>& end) {
        // Store meetings as (end_time, start_time, original_index)
        vector<tuple<int, int, int>> meetings;
        for (int i = 0; i < start.size(); i++) {
            // i+1 for 1-based indexing
            meetings.push_back({end[i], start[i], i + 1}); 
           
        }

        // Sort by end time
        sort(meetings.begin(), meetings.end());

        vector<int> result; // To store meeting indices
        int lastEnd = -1;

        // Traverse sorted meetings
        for (auto& m : meetings) {
            int e = get<0>(m);
            int s = get<1>(m);
            int idx = get<2>(m);

            // If meeting starts after last one ends
            if (s > lastEnd) {
                // Store index
                result.push_back(idx); 
                // Update last end time
                lastEnd = e; 
            }
        }
        return result;
    }
};
```
- Time complexity: O(n) + O(nlogn) + O(n) = O(n*(1+logn)) (We sort the entire start and end time array and then iterate over every interval one by one.)
- Space complexity: O(n) (additional space used to store tuple of start time, end time and index.)
