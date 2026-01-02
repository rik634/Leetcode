// problem statement: Given a positive integer n, set the rightmost unset (0) bit of its binary representation to 1 and return the resulting integer.
//If all bits are already set, return the number as it is.

// solution:
// Function to set the rightmost unset bit (0 -> 1)
int setRightmostUnsetBit(int n) {
    // Use bitwise OR with n+1 to set rightmost 0
    return n | (n + 1);
}
// time complexity: O(1)
// space complexity: O(1)
