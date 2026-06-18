# Game DP on intervals

## Use case:
- When: given an array/sequence, players pick from ends or sub-ranges.
- State: dp[i][j] = best score current player can get from subarray [i..j].
- Transition: dp[i][j] = max(arr[i] + total[i+1..j] - dp[i+1][j], arr[j] + total[i..j-1] - dp[i][j-1])

## Explaination
- Let me build this step by step — same approach as before, label states by hand first, spot the pattern, then generalise.

<img width="422" height="242" alt="image" src="https://github.com/user-attachments/assets/cc92f8a4-a4a1-4eec-b689-517dd0303d88" />
<img width="429" height="216" alt="image" src="https://github.com/user-attachments/assets/3584d323-32a3-4a84-aacb-be62c35529e3" />
<img width="368" height="287" alt="image" src="https://github.com/user-attachments/assets/2e59db46-a171-44ef-99bc-25955f05ee52" />
<img width="358" height="266" alt="image" src="https://github.com/user-attachments/assets/08416ccf-a371-41db-937f-1cda13fd6443" />
<img width="367" height="173" alt="image" src="https://github.com/user-attachments/assets/2694c4a0-5188-4581-bae0-4d04ac9f2978" />


- Let me build this step by step — same approach as before, label states by hand first, spot the pattern, then generalise.Walk the five tabs in order — each one builds on the previous. Here is the core logic stated plainly:
  
  1. Why greedy fails.You cannot just pick the bigger end each turn. Your pick affects what the opponent gets, which affects what you get next round. You have to think several moves ahead — that's exactly what DP does.
  2. The state definition is the key move. dp[i][j] = the best score the *current player* (whoever's turn it is) can guarantee from the subarray `arr[i..j]`. This is not Player 1's score — it's whichever player is currently facing that subarray. This makes the recurrence symmetric and clean.
  3. The recurrence in plain English.** If you pick the left end, you take `arr[i]` and leave `arr[i+1..j]` for your opponent. Your opponent then scores `dp[i+1][j]` from that. The total of the subarray is fixed, so *you* get `total - dp[i+1][j]`. Same logic for picking right. You take whichever gives you more.
  4. Fill order matters.** You must fill shorter subarrays before longer ones — the diagonal pattern. Length-1 first (base case = just take the coin), then length-2, then length-3, up to length-n. Tab 4 shows this — hover any cell to see exactly how it was computed from two smaller cells.
  5. Reading the final answer.** `dp[0][n-1]` is Player 1's score. Player 2's score is `total - dp[0][n-1]`. Compare the two to find the winner.


## practice problem
  1. https://leetcode.com/problems/stone-game/description
  2. 
