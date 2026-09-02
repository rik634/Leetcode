## Problem statement:
- You are given an array prices where prices[i] is the price of a given stock on the ith day.
- You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
- Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

### Brute force:
```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int mx = 0;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (prices[j] >= prices[i]) {
                    mx = max(mx, prices[j] - prices[i]);
                }
            }
        }
        return mx;
    }
};
```
- Time complexity: O(n*n)
- Space complexity: O(1)

### Optimized
```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int mx = 0;
        int mn = prices[0];
        for (int i = 1; i < n; i++) {
            int cost = prices[i] - mn;
            mx = max(mx, cost);
            mn = min(mn, prices[i]);
        }
        return mx;
    }
};
```
- Time complexity: O(n)
- Space complexity: O(1)

## Think
- If the interviewer says "can you avoid checking every pair", think: track the running minimum price seen so far, compare every day against just that one value.
- If the interviewer says "what if multiple transactions were allowed", think: that is a different problem, requiring a different, more general approach.
- If the interviewer says "how do you guarantee the sell day comes after the buy day", think: the running minimum only ever reflects days already passed, so any profit computed against it is automatically valid.

## Follow-up questions
1. Why does only the single lowest earlier price matter, rather than every earlier price individually?
   - For a fixed sell day, profit only depends on which earlier price you subtract — and since a lower buy price always yields equal or greater profit than a higher one regardless of the sell day, every earlier price except the minimum is strictly dominated and can be discarded. That's why tracking a single running minimum is sufficient, and it's exactly what collapses the problem from O(n²) pairwise comparisons down to a single O(n) pass.

2. How would this change if unlimited buy and sell transactions were allowed, as in "Best Time to Buy and Sell Stock II"?
   - Problem change: Now you can buy and sell as many times as you like, but you must sell before you buy again (can't hold multiple shares at once). Maximize total profit.
```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i - 1]) {
                profit += prices[i] - prices[i - 1];
            }
        }
        return profit;
    }
};
```
   - In problem I, you only cared about the one best buy point relative to a fixed sell day, because you could only transact once. With unlimited transactions, that constraint disappears — you can capture every profitable up-move in the price sequence, not just the single biggest one.
   - This flips the framing entirely: instead of "find the best single (buy, sell) pair," you want to sum up every day-to-day gain. Whenever tomorrow's price is higher than today's, you effectively "capture" that gain by conceptually buying today and selling tomorro
   - Why this greedy works — the key proof idea:
     - This relies on a clean telescoping argument. Suppose prices go 3 → 5 → 7 across three consecutive days. You could:
       - Buy at 3, sell at 7 directly → profit = 4
       - Or buy at 3, sell at 5, immediately buy at 5, sell at 7 → profit = (5-3) + (7-5) = 2 + 2 = 4
     - Both give the same total profit — the intermediate buy/sell at 5 cancels out algebraically: (5-3) + (7-5) = 7-3. So splitting one long upward run into many small one-day transactions never loses profit — it's mathematically identical.
   - Since splitting is "free," the optimal strategy is to decompose the whole price sequence into every maximal contiguous increasing run, and capture each one's full gain. And capturing a maximal increasing run is exactly equivalent to summing every single positive day-to-day difference along the way — which is exactly what the one-line greedy loop does. Days where price drops (prices[i] < prices[i-1]) simply contribute nothing and are skipped, since you'd never choose to "buy high, sell low."
   - Interestingly, both (I and II) are O(n)/O(1) — the constraint change (one transaction vs. unlimited) doesn't change the complexity class, but it completely changes what quantity you're tracking and why the greedy choice is valid. That contrast — "same complexity, different invariant, different proof" — is often exactly what an interviewer wants to hear you articulate.
   - With unlimited transactions, any long price increase can be losslessly decomposed into a chain of one-day buy-sell pairs — the intermediate trades cancel out algebraically — so the optimal strategy is simply to sum every positive day-to-day price difference. This replaces "track the single best buy point" with "capture every upward move," but keeps the same O(n) time and O(1) space.


3. How would you solve the variant with at most two transactions, "Best Time to Buy and Sell Stock III"?
   - Why the previous greedy tricks break down here:
     - Problem I only needed a running minimum. Problem II could greedily capture every upward move because transactions were unlimited. Problem III sits in between: you're capped at exactly two (or fewer) transactions, so you can no longer just grab every profitable wiggle — greedy capturing of every small up-move could burn through your transaction budget on tiny gains and leave you unable to capture a bigger one later. This constraint forces you into genuine dynamic programming, because the decision at each day now depends on which transaction number you're in — that's state you must track.
     - 
   - 

4. How would you adapt this approach if a transaction fee were charged on every sale?


5. How would you modify this to also return which two days achieve the maximum profit, not just the profit itself?
