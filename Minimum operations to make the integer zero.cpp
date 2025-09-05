// Level: Medium
class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        for (int t = 1; t <= 60; t++) {
            long long s = (long long)num1 - (long long)t * num2;
            if (s < 0) continue;
            if (s < t) continue;
            int ones = __builtin_popcountll(s);
            if (ones <= t) return t;
        }
        return -1;
    }
};

// time complexity: O(1), in worst case: O(60*60)
// space complexity: O(1)
