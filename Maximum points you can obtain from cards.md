## Problem statement
- Given N cards arranged in a row, each card has an associated score denoted by the cardScore array. Choose exactly k cards.
- In each step, a card can be chosen either from the beginning or the end of the row. The score is the sum of the scores of the chosen cards

### Brute force
- We can only take k cards, but from either end of the array. To find the maximum sum, we try all combinations of taking i cards from the start and (k- i) from the end, for all i from 0 to k.
-  The best combination gives the answer.

```cpp
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {

        int n = cardPoints.size();
        int lSum = 0;
        int rSum = 0;
        int mx = 0;
        for (int i = 0; i <= k; i++) {
            int temp = 0;
            for (int j = 0; j < i; j++) {
                temp += cardPoints[j];
            }
            for (int j = 0; j < (k - i); j++) {
                temp += cardPoints[n - j - 1];
            }
            mx = max(mx, temp);
        }
        return mx;
    }
};
```
- Time complexity: O(k*k)
- Space complexity: O(1)

### Optimized
- Instead of trying all combinations by recalculating front and back sums each time, we use a modified sliding window technique. We start by taking all k cards from the front,
- then gradually shift the window by removing one card from the front and adding one from the back.
- This keeps the number of selected cards fixed, but changes the selection balance between front and back. At each step, we update the score in constant time, which makes the solution much faster than brute force.
  
```cpp
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {

        int n = cardPoints.size();
        int l = 0;
        int r = n - 1;
        int mx = 0;
        for (int i = 0; i < k; i++) {
            mx += cardPoints[i];
        }
        l = k - 1;
        int temp = mx;
        while (l >= 0) {
            temp += cardPoints[r];
            r--;
            temp -= cardPoints[l];
            l--;
            mx = max(mx, temp);
        }
        return mx;
    }
};
```
- Time complexity: O(k) + O(k) = O(k)
- Space complexity: O(1)
