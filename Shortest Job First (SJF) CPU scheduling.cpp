// Level: easy
// Link: https://www.geeksforgeeks.org/problems/shortest-job-first/1
// Solution
class Solution {
  public:
    long long solve(vector<int>& bt) {
        // code here
        sort(bt.begin(),bt.end());
        
        int prev=0;
        int temp =0;
        int total=0;
        for(int i=0;i<bt.size();i++)
        {
           
            total+=temp;
            temp = prev+bt[i];
            prev=temp;
        }
        return floor(total/bt.size());
        
    }
};

// Time Complexity: O(N) +O(N*logN)
// Space Complexity: O(1)
