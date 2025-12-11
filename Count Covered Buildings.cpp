// Level: Medium
class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        
        int m = buildings.size();
         vector<int> minx(n + 1, n + 1);
        vector<int> maxx(n + 1, 0);
        vector<int> miny(n + 1, n + 1);
        vector<int> maxy(n + 1, 0);
        for(auto it:buildings)
        {
            int x = it[0];
            int y = it[1];
            minx[y] = min(minx[y], x);
            maxx[y] = max(maxx[y], x);
            miny[x] = min(miny[x], y);
            maxy[x] = max(maxy[x], y);
        }
        int count=0;
        for(auto it:buildings)
        {
            int r = it[0];
            int c = it[1];
           if(minx[c] < r && r < maxx[c] && miny[r] < c && c < maxy[r])
            {
                count++;
            }
        }
        return count;


    }
};
// Time complexity: O(m)
// space complexity: O(1)
