// problem statement: Given an integer n, return the number of set bits (1s) in its binary representation.
//Can you solve it in O(log n) time complexity?

// brute force:
class Solution {
public:
    // Function to count the number of set bits (1s) in the binary representation of n
    int countSetBits(int n) {
        int count = 0;  // Variable to store the count of set bits

        // Step 1: Count the number of set bits using bitwise operations
        while (n > 0) {
            count += (n & 1);  // Check if the least significant bit is set (1)
            n >>= 1;  // Right shift n by 1 to process the next bit
        }

        // Step 2: Return the count of set bits
        return count;
    }
};

// time complexity: O(logn)
// space complexity: O(1)

// optimized
class Solution {
public:
    // Function to count the number of set bits (1s) in the binary representation of n using Brian Kernighan's Algorithm
    int countSetBits(int n) {
        int count = 0;  // Variable to store the count of set bits

        // Step 1: While n is non-zero, turn off the rightmost set bit
        while (n) {
            n &= (n - 1);  // Turn off the rightmost set bit
            count++;  // Increment the count
        }

        // Step 2: Return the count of set bits
        return count;
    }
};
// time complexity: O(k) (k=number of set bits)
// space complexity:O(1)
