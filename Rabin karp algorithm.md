## Problem statement
- The Rabin-Karp algorithm is a string-searching algorithm that uses hashing to find a pattern within a text.
- While a brute-force approach checks every single character one by one, Rabin-Karp speeds things up by comparing "fingerprints" (hash values) first.

### How It Works
- The algorithm slides a window over the text, calculates a hash for the current window, and compares it to the pre-calculated hash of the pattern.
  1. Calculate the Pattern Hash: Compute the hash value of the pattern you are looking for.
  2. Calculate the Initial Text Hash: Compute the hash for the first m characters of the text (where $m$ is the pattern length).
  3. Slide and Compare:  If the hashes match, perform a character-by-character check to confirm (to avoid collisions).If they don't match, slide the window one position to the right.
  4. Rolling Hash: Instead of re-calculating the hash from scratch for every window, the algorithm "rolls" the hash by removing the leading character and adding the trailing character.

### The Rolling Hash Math
- To make this efficient, we use a polynomial rolling hash. For a string S, the hash $H$ is calculated as:
    <img width="620" height="64" alt="image" src="https://github.com/user-attachments/assets/822c6ee0-ed24-45ce-acc2-5a15107d0aeb" />
- b: A base (usually the number of characters in the alphabet, like 256).
- q: A large prime number (to keep the hash values manageable and reduce collisions).

### Why the "Rolling" part matters:
- When moving the window from index i to i+1, the new hash H_{next} is derived from the old hash H_{prev} using this logic
  1. Subtract the value of the character leaving the window.
  2. Multiply by the base $b$ to shift everything left.
  3. Add the value of the new character entering the window.
 

### Solution
```cpp
// d is the number of characters in the input alphabet
#define d 256 

void rabinKarp(string pat, string txt, int q) {
    int m = pat.length();
    int n = txt.length();
    int p = 0; // hash value for pattern
    int t = 0; // hash value for text
    int h = 1;

    // h = pow(d, m-1) % q. Used to "remove" the leading digit.
    for (int i = 0; i < m - 1; i++)
        h = (h * d) % q;

    // Calculate initial hashes
    for (int i = 0; i < m; i++) {
        p = (d * p + pat[i]) % q;
        t = (d * t + txt[i]) % q;
    }

    for (int i = 0; i <= n - m; i++) {
        // If hashes match, check characters to handle collisions
        if (p == t) {
            int j;
            for (j = 0; j < m; j++) {
                if (txt[i + j] != pat[j]) break;
            }
            if (j == m) cout << "Pattern found at index " << i << endl;
        }

        // Rolling hash: Remove leading, shift, add trailing
        if (i < n - m) {
            t = (d * (t - txt[i] * h) + txt[i + m]) % q;
            if (t < 0) t = (t + q); // Keep hash positive
        }
    }
}

int main() {
    string txt = "ABABDABACDABABCABAB";
    string pat = "ABABCABAB";
    int q = 101; // A prime number for the modulus
    rabinKarp(pat, txt, q);
    return 0;
}
```
### Performance Summary 
- Best Case: O(n + m),  Occurs when there are no hash collisions
- Worst Case: O(n * m), Occurs if the hash function is poor, causing a "spurious hit" at every step.
- Space: O(1), It only needs to store a few variables for the hashes.
