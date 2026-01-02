// problem statement:  Given two integers a and b, swap them in-place using only 2 variables (without using a temporary variable).
// solution:
void swapXOR(int &a, int &b) {
    // Step 1: XOR a and b, store in a
    a = a ^ b;

    // Step 2: XOR new a with b, result is original a → store in b
    b = a ^ b;

    // Step 3: XOR new a with new b, result is original b → store in a
    a = a ^ b;
}

// time complexity:O(1)
// space complexity:O(1)
