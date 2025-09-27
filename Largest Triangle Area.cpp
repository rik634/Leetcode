// Level: easy
class Solution {
public:
    double area(int i, int j, int k, vector<vector<int>>& points )
    {
        int x1 = points[i][0];
        int y1 = points[i][1];
        int x2 = points[j][0];
        int y2 = points[j][1];
        int x3 = points[k][0];
        int y3 = points[k][1];
        double rem = abs(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2));
        return rem/2;
    }
    double largestTriangleArea(vector<vector<int>>& points) {
        
        int n = points.size();
        double mx=0;
        for(int i=0;i<n-2;i++)
        {
            for(int j=i+1;j<n-1;j++)
            {
                for(int k=j+1;k<n;k++)
                {
                    mx=max(mx,area(i,j,k,points));
                }
            }
        }
        return mx;
    }
};
// time complexity: O(n^3)
// space complexity: O(1)
