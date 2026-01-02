// Level: Easy
// Link: https://leetcode.com/problems/minimum-bit-flips-to-convert-number/description/
// Solution
class Solution {
public:
    int minBitFlips(int start, int goal) {
        
        int ans = start ^ goal;
        int count=0;
        while(ans>0)
        {
            if(ans&1==1) // odd
            {
                count++;
            }
            ans = ans >> 1;
        }
        if(ans==1)
        {
            count++;
        }
        return count;
    }
};
// Time Complexity: O(log (start^goal)) (base is 2)
// Space Complexity: O(1)

// optimal
class Solution {
public:
    int minBitFlips(int start, int goal) {

        bitset<32> b(start^goal); // 10 is 1010 in binary
int count = b.count();
return count;
    }
};
// time complexity: o(1)
// space complexity:O(1)

// another optimal
class Solution {
public:
    int minBitFlips(int start, int goal) {

        
        int count =__builtin_popcount(start^goal);
        return count;
    }
};
// time complexity: o(1)
// space complexity:O(1)

// another
class Solution {
public:
  
    int minBitsFlip(int start, int goal) {
      
        int num = start ^ goal;
        int count = 0;

        for(int i = 0; i < 32; i++) {

            count += (num & 1); 
            num = num >> 1;
        }
        return count;
    }
};
// time complexity: o(1)
// space complexity:O(1)
