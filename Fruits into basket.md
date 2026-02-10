## Problem statement
- You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array fruits where fruits[i] is the type of fruit the ith tree produces.
- You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow:
  1. You only have two baskets, and each basket can only hold a single type of fruit. There is no limit on the amount of fruit each basket can hold.
  2. Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right. The picked fruits must fit in one of your baskets.
  3. Once you reach a tree with fruit that cannot fit in your baskets, you must stop.
- Given the integer array fruits, return the maximum number of fruits you can pick- 

### Brute force:
```cpp
class Solution {
public:
    // Function to calculate maximum fruits collected  
    // with at most two distinct types from any start point 
    int totalFruit(vector<int>& fruits) {

        // Variable to store the maximum fruits collected
        int maxFruits = 0;

        // Loop over each possible starting point
        for (int start = 0; start < fruits.size(); ++start) {

            // Create a map to store the count of fruit types
            unordered_map<int, int> basket;

            // Initialize current count
            int currentCount = 0;

            // Traverse from current start to the end
            for (int end = start; end < fruits.size(); ++end) {

                // Add current fruit to the basket
                basket[fruits[end]]++;

                // If basket has more than 2 types, break
                if (basket.size() > 2) {
                    break;
                }

                // Increase current fruit count
                currentCount++;
            }

            // Update maximum fruits collected
            maxFruits = max(maxFruits, currentCount);
        }

        // Return the result
        return maxFruits;
    }
};
```
- Time complexity: O(n*n)
- Space complexity: O(1)

### Solution
```cpp
class Solution {
public:
    int totalFruit(vector<int>& fruits) {

        int n = fruits.size();
        unordered_map<int, int> mp;
        int l = 0;
        int r = 0;
        int mx = 0;
        while (r < n) {
            mp[fruits[r]]++;
            while (mp.size() > 2) {
                mp[fruits[l]]--;
                if (mp[fruits[l]] == 0) {
                    mp.erase(fruits[l]);
                }
                l++;
            }

            mx = max(mx, r - l + 1);
            r++;
        }
        return mx;
    }
};
```
- Time complexity: O(n)
- Space complexity: O(1)

### Optimized
```cpp
class Solution {
public:
    // Function to find the maximum number of fruits we can collect
    // with at most two types of fruits in the baskets.
    int totalFruit(vector<int>& fruits) {
        
        // Variable to store the maximum number of fruits collected
        int maxlen = 0;
        
        // Variables to track the last two fruit types and their counts
        int lastfruit = -1, secondlastfruit = -1;
        
        // Count of current window size and the last fruit streak
        int currcount = 0, lastfruitstreak = 0;

        // Traverse through each fruit in the array
        for (int fruit : fruits) {
            
            // If current fruit is same as last or second last, increase window
            if (fruit == lastfruit || fruit == secondlastfruit) {
                currcount++;
            } else {
                // Reset window size to size of last fruit streak + 1 (current fruit)
                currcount = lastfruitstreak + 1;
            }

            // Update streak count
            if (fruit == lastfruit) {
                lastfruitstreak++;
            } else {
                lastfruitstreak = 1;
                secondlastfruit = lastfruit;
                lastfruit = fruit;
            }

            // Update the maximum length
            maxlen = max(maxlen, currcount);
        }

        return maxlen;
    }
};
```
- Time complexity: O(n)
- Space complexity: O(1)
