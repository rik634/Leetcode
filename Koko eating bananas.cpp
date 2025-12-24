// level: Medium
// brute force

class Solution {
public:
  
    int calculateTotalHours(vector<int>& a, int hourly) {
        int totalHours = 0;
        for (int pile : a) {
            totalHours += (pile + hourly - 1) / hourly;
        }
        return totalHours;
    }

    // Function to find minimum eating speed
    int minEatingSpeed(vector<int>& a, int h) {
        // Find maximum pile size
        int maxVal = *max_element(a.begin(), a.end());

        // Try every possible speed
        for (int i = 1; i <= maxVal; i++) {
            int hours = calculateTotalHours(a, i);

            // If hours fit within h
            if (hours <= h) {
                return i;
            }
        }
        return maxVal;
    }
};
// time complexity: O(n*mx)
// space complexity: O(1)


// binary search
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int n = piles.size();
        int mx=INT_MIN;
        for(int i=0;i<n;i++)
        {
            mx=max(mx,piles[i]);
        }
        int l=1;
        int r=mx;
        int ans=mx;
        while(l<=r)
        {
            int mid = (l+r)/2;
            long long count=0;
            for(int i=0;i<n;i++)
            {
                count+=ceil((double)piles[i]/mid);
            }
            
            if(count<=h)
            {
                ans=mid;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }

        }
        return ans;
    }
};
// Time complexity: O(n*log(mx))
// space complexity: O(1)
