// problem statement:  Given an integer n, return all binary strings of length n that do not contain consecutive 1s. Return the result in lexicographically increasing order.
//A binary string is a string consisting only of characters '0' and '1'.

// solution:
void generate(int n, string curr, vector<string>& result) {
    // Base case: if length is n, add to result
    if (curr.length() == n) {
        result.push_back(curr);
        return;
    }

    // Always try adding '0'
    generate(n, curr + "0", result);

    // Add '1' only if previous char is not '1'
    if (curr.empty() || curr.back() != '1') {
        generate(n, curr + "1", result);
    }
}
// time complexity: o(2^n)
// space complexity:O(n)
