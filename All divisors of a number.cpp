// problem statement: You are given an integer n. You need to find all the divisors of n. Return all the divisors of n as an array or list in a sorted order. 
//A number which completely divides another number is called it's divisor.

// brute force
class Solution {
public:
    vector<int> divisors(int n) {
        vector<int> ans;
        for(int i=1; i <= n; i++) {
            if(n % i == 0) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
// time complexity: O(n)
// space complexity: O(sqrt(n)) A number N can have at max 2*sqrt(N) divisors, which are stored in the array.

// optimized
class Solution {
public:
    vector<int> divisors(int n) {
        vector<int> ans;
        int sqrtN = sqrt(n);
        for(int i=1; i <= sqrtN; i++) {
            if(n % i == 0) {
                ans.push_back(i);
                if(i != n / i) {
                    ans.push_back(n/i);
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
// time complexity: O(sqrt(N)) + O(K*Log(K)) – Iterating sqrt(N) times, and performing constant time operations in each pass to get all the divisors in the list. 
//Sorting the list of divisors takes O(K*Log(K)) time where K is the number of divisors of the number.
// space complexity: O(sqrt(N)) – A number N can have at max 2*sqrt(N) divisors, which are stored in the array.
