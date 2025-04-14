// Level: Easy
// Link: https://leetcode.com/problems/count-good-triplets/description/
// Solution

class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        
        int count=0;
        int n = arr.size();
        for(int i=0;i<n-2;i++)
        {
            for(int j=i+1;j<n-1;j++)
            {
                for(int k=j+1;k<n;k++)
                {
                    if((abs(arr[i]-arr[j])<=a) && (abs(arr[j]-arr[k])<=b) && (abs(arr[k]-arr[i])<=c))
                    {
                        count++;
                    }
                }
            }
        }
        return count;
    }
};
