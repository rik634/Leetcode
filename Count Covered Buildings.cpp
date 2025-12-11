// Level: Medium
class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        
        int m = buildings.size();
        unordered_map<int,vector<int>> row;
        unordered_map<int,vector<int>> col;
        int minX=INT_MAX;
        int maxX=INT_MIN;
        int minY=INT_MAX;
        int maxY=INT_MIN;
        for(auto it:buildings)
        {
            int x = it[0];
            int y = it[1];
            minX=min(minX,x);
            maxX=max(maxX,x);
            minY=min(minY,y);
            maxY=max(maxY,y);
        }
        int count=0;
        for(auto it:buildings)
        {
            int r = it[0];
            int c = it[1];
            if(r>minX && r<maxX && c>minY && c<maxY)
            {
                count++;
            }
        }
        return count;


    }
};
// Time complexity: O(m)
// space complexity: O(1)
