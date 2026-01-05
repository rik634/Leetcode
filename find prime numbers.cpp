// used to find all prime numbers up to a specified limit $n$. 

// method-1: Sieve of Eratosthenes
// code:
#include <iostream>
#include <vector>

void sieveOfEratosthenes(int n) {
    // Create a boolean vector "isPrime[0..n]" and initialize all as true.
    std::vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int p = 2; p * p <= n; p++) {
        // If isPrime[p] is not changed, then it is a prime
        if (isPrime[p] == true) {
            // Update all multiples of p starting from p*p
            for (int i = p * p; i <= n; i += p)
                isPrime[i] = false;
        }
    }

    // Print primes
    for (int p = 2; p <= n; p++) {
        if (isPrime[p]) std::cout << p << " ";
    }
}
// time complexity:O(nloglogn)

// method-2: Sieve of Euler (Linear Sieve)
// code:
#include <iostream>
#include <vector>

void sieveOfEuler(int n) {
    std::vector<int> primes;
    std::vector<bool> isNotPrime(n + 1, false);

    for (int i = 2; i <= n; i++) {
        if (!isNotPrime[i]) {
            primes.push_back(i);
        }

        // For every number i, multiply it by all primes found so far
        for (int p : primes) {
            if (i * p > n) break;
            
            isNotPrime[i * p] = true;

            // This is the "Magic Rule": 
            // If p divides i, then p is the smallest prime factor of (i * p).
            // We stop here to ensure each composite is marked only once.
            if (i % p == 0) break;
        }
    }

    // Print primes
    for (int p : primes) {
        std::cout << p << " ";
    }
}
// Time complexity: O(n)
