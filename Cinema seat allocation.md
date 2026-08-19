## Problem statement
- A cinema has n rows of seats, numbered from 1 to n. Each row has 10 seats, numbered from 1 to 10.
- You are given a 2D integer array reservedSeats, where reservedSeats[i] = [rowi, seati] means that seat seati in row rowi is already reserved.
- A four-person group must be assigned to four seats in the same row. The group can be seated in one of the following seat blocks:

seats 2, 3, 4, 5
seats 4, 5, 6, 7
seats 6, 7, 8, 9
- A block can be used only if none of its seats are reserved. Each seat can be assigned to at most one group.
- Return an integer denoting the maximum number of four-person groups that can be assigned.

### Solution
```cpp
class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        
        unordered_map<int,unordered_set<int>> mp;
        for(int i=0;i<reservedSeats.size();i++){
            int r = reservedSeats[i][0];
            int c = reservedSeats[i][1];
            mp[r].insert(c);
        }
        int count=0;
        for(auto it:mp){
            int r = it.first;
            auto st = it.second;
            int a=0;
            int b=0;
            int c=0;
            if(st.find(2)!=st.end() || st.find(3)!=st.end()){
                a=1;
            }
            if(st.find(4)!=st.end() || st.find(5)!=st.end()){
                a=1;
                b=1;
            }
            if(st.find(6)!=st.end() || st.find(7)!=st.end()){
                b=1;
                c=1;
            }
            if(st.find(8)!=st.end() || st.find(9)!=st.end()){
                c=1;
            }
            int sum=a+b+c;
            if(sum==0){
                count+=2;
            }
            else if(sum==3){
                count+=0;
            }
            else{
                count+=1;
            }
        }
        count+= (n-(mp.size()))*2;
        return count;
    }
};
```
- Time complexity: O(M)
- Space complexity:O(M) (M= number os reserved seats)
