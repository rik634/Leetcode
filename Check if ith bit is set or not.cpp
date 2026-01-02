// problem statement: Given two integers n and i, return true if the ith bit in the binary representation of n (counting from the least significant bit, 0-indexed) is set (i.e., equal to 1). Otherwise, return false.

// brute force
class Solution {
public:
    // Function to check if the i-th bit of number n is set (1)
    bool checkIthBit(int n, int i) {
        string binary = "";
        // Convert the number into its binary representation
        while (n > 0) {
            binary += (n % 2 == 0 ? '0' : '1');  // Append '0' or '1' depending on the least significant bit
            n /= 2;  // Move to the next higher bit
        }

        // If the bit index is greater than the length of the binary string, the bit is 0
        if (i >= binary.size()) return false;

        // Return true if the i-th bit is 1, otherwise false
        return binary[i] == '1';
    }
};
// time complexity: O(logn)
// space complexity: O(logn)

// optimized
class Solution {
public:
    // Function to check if the i-th bit of number n is set (1)
    bool checkIthBit(int n, int i) {
        // Check if the i-th bit is set using bitwise AND operation
        return (n & (1 << i)) != 0;  // If the i-th bit is 1, the result will be non-zero
    }
};
// time complexity:O(1)
// space complexity:O(1)
