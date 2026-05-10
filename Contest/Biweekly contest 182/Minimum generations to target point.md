## Problem statement
- You are given a 2D integer array points where points[i] = [xi, yi, zi] represents a point in 3D space, and an integer array target representing a target point.
- Define generation 0 as the initial list of points. For each integer k >= 1, form generation k as follows:
  - Consider every pair of two distinct points a = [x1, y1, z1] and b = [x2, y2, z2] taken from all points produced in generations 0 through k - 1.
  - For each such pair, compute c = [floor((x1 + x2) / 2), floor((y1 + y2) / 2), floor((z1 + z2) / 2)] and collect every such c into a generation k.
  - All points in the generation k are produced simultaneously from points in generations 0 through​​​​​​​ k - 1.
  - After generation k is formed, the points in the generation k are considered available for forming later generations.
- Return the smallest integer k such that the target appears in one of the generations 0 through k. If the target is already in the initial points, return 0. If it is impossible to obtain the target, return -1.
- Notes:
  - floor denotes rounding down to the nearest integer.
  - "Two distinct points" means the two chosen points must have different (x, y, z) coordinates. A point cannot be paired with itself, and pairing two points with identical coordinates is not possible.
 
## Solution
```cpp
class Solution {
public:
    int minGenerations(vector<vector<int>>& points, vector<int>& target) {

        set<vector<int>> st;
        for (auto it : points) {
            st.insert({it[0], it[1], it[2]});
            if (it[0] == target[0] && it[1] == target[1] &&
                it[2] == target[2]) {
                return 0;
            }
        }
        int k=0;
        bool flag=false;
        while (!flag) {
            vector<vector<int>> v(st.begin(),st.end());
            k++;
            int size = st.size();
            for (int i=0;i<size-1;i++) {
                for (int j=i+1;j<size;j++) {
                    
                    int a = floor((v[i][0] + v[j][0]) / 2);
                    int b = floor((v[i][1]+ v[j][1]) / 2);
                    int c = floor((v[i][2]+ v[j][2]) / 2);
                    if (a==target[0] && b==target[1] && c==target[2]){
                        flag=true;
                    }
                    st.insert({a,b,c});
                }
            }
            if(flag==true){
                return k;
            }
            else if(size==st.size()){
                return -1;
            }
        }
        return -1;
    }
};
```
- Time complexity: O(G*S*SlogS) (G= number of generations, S= number of elements in set)
- Space complexity: O(S)
