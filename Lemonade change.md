## Problem statement
- Given an array representing a queue of customers and the value of bills they hold, determine if it is possible to provide correct change to each customer.
- Customers can only pay with 5$, 10$ or 20$ bills and we initially do not have any change at hand. Return true, if it is possible to provide correct change for each customer otherwise return false.

### Solution
```cpp
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int, int> mp;

        for (auto it : bills) {
            if (it == 5) {
                mp[it]++;
            } else if (it == 10) {
                mp[it]++;
                if (mp[5] > 0) {
                    mp[5]--;
                } else {
                    return false;
                }
            } else if (it == 20) {
                mp[it]++;
                if (mp[5] > 0 && mp[10] > 0) {
                    mp[5]--;
                    mp[10]--;
                } else if (mp[5] >= 3) {
                    mp[5] -= 3;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};
```
- Time complexity: O(n)
- Space complexity: O(1)
