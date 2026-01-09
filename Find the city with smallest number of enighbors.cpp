// level: Medium
// problem statement:  There are n cities numbered from 0 to n-1. Given the array edges where edges[i] = [fromi, toi,weighti] represents a bidirectional and weighted edge between cities fromi and toi, and given the integer distance Threshold. 
//You need to find out a city with the smallest number of cities that are reachable through some path and whose distance is at most Threshold Distance, If there are multiple such cities, our answer will be the city with the greatest number.
//Note: that the distance of a path, connecting cities i and j are equal to the sum of the edges' weights along that path.

// solution:
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
        for(int i=0;i<n;i++){
            dist[i][i]=0;
        }
        for(auto it:edges) {
            dist[it[0]][it[1]]=it[2];
            dist[it[1]][it[0]]=it[2];
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++) {
                for(int j=0;j<n;j++){
                    if(dist[i][k]!=INT_MAX && dist[k][j]!=INT_MAX)
                    {
                        dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                    }
                }
            }
        }
        int mx=INT_MAX;
        int ind=0;
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<n;j++){
                if(dist[i][j]<=distanceThreshold){
                    count++;
                }
            }
            if(count<=mx){
                mx=count;
                ind=i;
            }
        }
        return ind;
    }
};
// Time complexity: O(n) + O(m) + O(n*n*n) = O(n^3)
// space complexity: O(n*n)
