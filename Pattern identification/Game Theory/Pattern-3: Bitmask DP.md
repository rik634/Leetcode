# Bitmask DP

## Use case
- When: n ≤ 20, state is a subset of elements used.
- State: dp[mask] = can current player win from this subset remaining?
- Who moves: popcount(mask) % 2 tells you whose turn it is.

## Explain

<img width="379" height="214" alt="image" src="https://github.com/user-attachments/assets/6cc80569-e8c0-4b99-b0c9-4c9a71e3dc6d" />
<img width="429" height="407" alt="image" src="https://github.com/user-attachments/assets/80195b9b-ed7c-49a2-a7d7-0ebe39bce63a" />
<img width="345" height="377" alt="image" src="https://github.com/user-attachments/assets/bfd2fa99-5975-407d-afcf-af1737bd418c" />
<img width="453" height="294" alt="image" src="https://github.com/user-attachments/assets/a505d258-c8fc-4081-a9e5-169185bc460b" />

- Why bitmask, not a simple array. In the stone game, one number (stones left) fully described the state. Here the state is: which numbers are still on the table, plus what was picked last (since that determines what's valid next). You need to track a subset — and a bitmask is the most compact way to represent any subset of n elements as a single integer.
- How to read a mask. If your set is [2, 3, 6] and mask = 101 in binary = 5, that means elements at index 0 and 2 are picked (2 and 6), and index 1 is still available (3). Whose turn it is follows automatically — count the 1-bits, even = Player 1, odd = Player 2.
- The state is dp(mask, last), not just dp(mask). The mask tells you which numbers are gone. last tells you which number was picked most recently, because your valid moves are restricted to divisors of last. Both together fully describe the game position.
- The recurrence is identical to every other game you've seen. From state (mask, last), try every valid pick v (where v divides last and v is still in the set). If any of those leads to a Lose state for the opponent — you Win. If all lead to Win states for the opponent — you Lose. Base case: no valid picks → Lose.
- Complexity. With n elements there are 2ⁿ masks and n possible last-picks, so the DP table has n × 2ⁿ states. Each state checks at most n moves. Total: O(n² × 2ⁿ). This is why bitmask DP only works for small n (usually n ≤ 20, comfortably n ≤ 15 for this variant). 

## Comparison with pattern-1
- Here is the exact parallel with Pattern 1, stated plainly:
- In Pattern 1 your states were n=0, 1, 2, 3 … — a row of integers. You labelled each one W or L by asking "can I move to any L state?" The labels formed a repeating pattern like L W W W L W W W… so you could write n % 4 == 0 → Lose.
- In Bitmask DP your states are {}, {1}, {2}, {1,2}, {3} … — a row of subsets. You label each one W or L by asking the exact same question: "can I move to any L state?" The labels do NOT form a repeating pattern — they depend on which numbers are available and what the current total is. So you cannot write a formula. Instead you store every label in a dictionary (memo) and look it up. That dictionary is your DP table. The mask (an integer like 0, 1, 2, 3…) is just your way of indexing into that table — it plays the same role that n played in Pattern 1.
- That is the only real difference. Same W/L rule, same labelling process, just a different shape of state.

### Practice problems
1. https://leetcode.com/problems/can-i-win/?envType=problem-list-v2&envId=game-theory
2. 
