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

### bitwise solution

#### explanation
- Core Idea: Representing Seats 2 to 9 as BitsSeats 1 and 10 are irrelevant because a family of 4 needs consecutive seats within $\{2,3,4,5\}$, $\{4,5,6,7\}$, or $\{6,7,8,9\}$
- The code maps seats 2 through 9 to 8 bits (index 0 to 7):
  <img width="391" height="194" alt="image" src="https://github.com/user-attachments/assets/7fa877cb-ff6a-483e-a763-fe49e20b2080" />

- Step-by-Step Breakdown
  1. Mask Definitions
     - The code defines invalidation masks. A bit set to 1 in these masks indicates seats that block seating in that area:
       <img width="835" height="237" alt="image" src="https://github.com/user-attachments/assets/b7335f21-ab17-4cf3-a345-68fb4f857b0b" />
   
  2. Building Row Bitmasks
    <img width="882" height="375" alt="image" src="https://github.com/user-attachments/assets/3335f039-44ed-4a8a-885d-9413cdd0fb35" />

  3.Counting Available Groups

  <img width="891" height="582" alt="image" src="https://github.com/user-attachments/assets/c4fba073-443a-4bb0-b782-efc91ea67192" />
  <img width="889" height="560" alt="image" src="https://github.com/user-attachments/assets/79f127e2-526b-4b75-be21-41589f07ff56" />
 
 
```cpp
class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int left = 0b11110000;
        int middle = 0b11000011;
        int right = 0b00001111;

        unordered_map<int, int> occupied;
        for (const vector<int>& seat : reservedSeats) {
            if (seat[1] >= 2 && seat[1] <= 9) {
                occupied[seat[0]] |= (1 << (seat[1] - 2));
            }
        }

        int ans = (n - occupied.size()) * 2;
        for (auto& [row, bitmask] : occupied) {
            if (((bitmask | left) == left) || ((bitmask | middle) == middle) ||
                ((bitmask | right) == right)) {
                ++ans;
            }
        }
        return ans;
    }
};
```
- Time xomplexity: O(M)
- Space complexity: O(M) (m= number of reserved seats)
