// problem sattement:  Given a non-negative integer n, determine whether it is odd. Return true if the number is odd, otherwise return false. A number is odd if it is not divisible by 2 (i.e., n % 2 != 0).
// clue: if the number is odd, last bit is set, or else not set
// brute solution:
class Solution {
public:
    // Function to check if a number is odd
    bool isOdd(int n) {
        return (n % 2 != 0);  // Return true if the number is odd, else false
    }
};
// time complexity:O(1)
// space complexity:O(1)

// Bit maipulation
class Solution {
public:
    // Function to check if a number is odd
    bool isOdd(int n) {
        return (1<<0)&num!=0;  // Return true if the number is odd, else false
    }
};
// time complexity:O(1)
// space complexity:O(1)
