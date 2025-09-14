// Level: Eas
class Solution {
public:
    int earliestTime(vector<vector<int>>& tasks) {

        int n = tasks.size();
        int mn=INT_MAX;
        for(int i=0;i<n;i++){
            mn=min(mn,tasks[i][0]+tasks[i][1]);
        }
        return mn;
    }
};

// time complexity: O(n)
// space complexity: O(1)
