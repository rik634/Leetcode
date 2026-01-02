// problem statement: Given two integers L and R. Find the XOR of the elements in the range [L , R].
// brute force
class Solution {
public:
    int findRangeXOR(int l, int r){			
		int ans = 0;
		for(int i=l; i <= r; i++) {
		    ans ^= i;
		}
		return ans;
	}
};
// time complexity: O(R-L+1)
// space complexity: O(1)

// optimized
class Solution {
private:
  
    int XORtillN(int n) {
        if(n % 4 == 1) return 1;
        if(n % 4 == 2) return n+1;
        if(n % 4 == 3) return 0;
        return n;
    }
    
public:
    /* Function to find the XOR 
    of numbers from L to R*/
    int findRangeXOR(int l, int r){			
		return XORtillN(l-1) ^ XORtillN(r);
	}
};
// Time complexity: O(1)
// Space complexity: O(1)
