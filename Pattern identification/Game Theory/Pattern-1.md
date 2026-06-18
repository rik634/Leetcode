# Pattern -1: Single integer state, Pure math/ closed form

## Use case:
- When: state is single number (stones in a pile, tokens on a line)
- How: . Check states 0,1,2,....,20 by hand, if W (win) or L(Lose). Find the period. A pattern always appears in ≤ 2× the move-set range.
- Example: Can pick 1 or 3. Losing when n % 4 == 0


## example:
- Here's the key insight first: to find the pattern, you don't need theory — you just mechanically label 10–15 states as Win (W) or Lose (L) using the P/N position rules, stare at the result, and the period jumps out at you.
- Let me build an interactive explorer so you can see it happen live:The widget above is fully interactive — toggle any move values (1–6) or click the presets to instantly see the W/L grid, the step-by-step derivation, and the formula for any move set.

<img width="440" height="251" alt="image" src="https://github.com/user-attachments/assets/583dcbf4-b36c-4f95-8240-14207a901aad" />

-  step by step derivation:
<img width="420" height="246" alt="image" src="https://github.com/user-attachments/assets/89dd3dde-3a35-405d-adba-de6bab18fe4e" />
<img width="416" height="253" alt="image" src="https://github.com/user-attachments/assets/2c2748bc-a4ae-4ce8-affc-8c7b2aa21ae3" />
<img width="429" height="127" alt="image" src="https://github.com/user-attachments/assets/6cc0795a-4de2-4d26-ab8e-e232dfb7604f" />

- 
- Here's the exact process you should follow in an OA when you see a game theory problem with a single pile:
  1. label states 0 to ~15 by hand.** `n=0` is always L (no moves = you lose). For each subsequent n, ask: can I reach any L state? If yes → W. If no → L. This takes 2 minutes.
  2. stare at the sequence.** For pick-1-or-3 you get `L W L W W W L W L W W W L…` — the pattern `L W W W` repeats with period 4.
  3. write the formula.** Lose iff `n % 4 == 0`. Done.
  4. Why period = 4 specifically?** It's always `max(move) + 1` as a starting guess — for moves {1, 3}, max is 3, so check period 4 first. This heuristic works for most clean move sets.
  5. The general rule** for "pick 1 to k": lose iff `n % (k+1) == 0`. For pick-{1,3} since the moves are not consecutive, you can't use the formula directly — you must compute it. But the period is still small (≤ sum of max moves).

### Practice problem
1. https://www.hackerrank.com/challenges/game-of-stones-1
2. https://leetcode.com/problems/divisor-game/description/
3. https://leetcode.com/problems/nim-game/description/
4. https://leetcode.com/problems/find-the-winning-player-in-coin-game/description
5. 
-
