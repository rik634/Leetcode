// Level: Easy
// Link: https://leetcode.com/problems/assign-cookies/description/
// problem statement: Consider a scenario where a teacher wants to distribute cookies to students, with each student receiving at most one cookie. 
//Given two arrays, student and cookie, the ith value in the student array describes the minimum size of cookie that the ith student can be assigned. 
//The jth value in the cookie array represents the size of the jth cookie. 
//If cookie[j] >= student[i], the jth cookie can be assigned to the ith student. Maximize the number of students assigned with cookies and output the maximum number.

// brute force (recursion)
class Solution {
public:
    int f(int sInd, int gInd, vector<int>& s, vector<int>& g) {
        if (sInd >= s.size() || gInd >= g.size()) {
            return 0;
        }
        int res = 0;
        // skip giving the current cookie to child, move to next cookie for the
        // same child
        res = max(res, f(sInd + 1, gInd, s, g));
        if (s[sInd] >= g[gInd]) {
            // children is satisfied with cookie, so move to next child and
            // cookie
            res = max(res, 1 + f(sInd + 1, gInd + 1, s, g));
        }
        return res;
    }
    int findContentChildren(vector<int>& g, vector<int>& s) {

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        return f(0, 0, s, g);
    }
};
// Time complexity:  O(nlogn) + O(mlogm) (sorting)+ O(2^(m+n)) (m=size of g, n=size of s)
// space complexity: O(m+n) (recursive stack space)

// memoization
class Solution {
public:
    int f(int sInd, int gInd, vector<int>& s, vector<int>& g,vector<vector<int>>& dp) {
        if (sInd >= s.size() || gInd >= g.size()) {
            return 0;
        }
        if(dp[gInd][sInd]!=-1)
        {
            return dp[gInd][sInd];
        }
        int res = 0;
        // skip giving the current cookie to child, move to next cookie for the
        // same child
        res = max(res, f(sInd + 1, gInd, s, g,dp));
        if (s[sInd] >= g[gInd]) {
            // children is satisfied with cookie, so move to next child and
            // cookie
            res = max(res, 1 + f(sInd + 1, gInd + 1, s, g,dp));
        }
        return dp[gInd][sInd]=res;
    }
    int findContentChildren(vector<int>& g, vector<int>& s) {

        int m = g.size();
        int n = s.size();
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return f(0, 0, s, g,dp);
    }
};
// Time complexity: O(nlogn) + O(mlogm) + O(n*m)
// space complexity: O(n*m)+ O(m+n) (recursive stack space)

// tabulation
class Solution {
public:
    
    int findContentChildren(vector<int>& g, vector<int>& s) {

        int m = g.size();
        int n = s.size();
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));

        for(int i=m-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                int skip = dp[i][j+1];
                int take=0;
                if(g[i]<=s[j])
                {
                    take = 1 + dp[i+1][j+1];
                }
                dp[i][j]=max(skip,take);
            }
        }
        return dp[0][0];
    }
};
// Time complexity: O(nlogn) + O(mlogm) + O(n*m)
// space complexity: O(n*m)

// space optimized
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {

        int m = g.size();
        int n = s.size();
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        vector<int> prev(n + 1, 0);
        for (int i = m - 1; i >= 0; i--) {
            vector<int> temp(n + 1, 0);
            for (int j = n - 1; j >= 0; j--) {
                int skip = temp[j + 1];
                int take = 0;
                if (g[i] <= s[j]) {
                    take = 1 + prev[j + 1];
                }
                temp[j] = max(skip, take);
            }
            prev = temp;
        }
        return prev[0];
    }
};
// Time complexity: O(nlogn) + O(mlogm) + O(n*m)
// space complexity: O(n)


// greedy approach
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {

        int m = g.size();
        int n = s.size();
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int l = 0;
        int r = 0;
        int count = 0;
        while (l < m && r < n) {
            if (g[l] <= s[r]) {
                count++;
                l++;
            }
            r++;
        }
        return count;
    }
};

// Time complexity: O(M*logM) + O(N*logN) + O(n+m)
// Space Complexity: O(1)

