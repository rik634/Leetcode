// Level: Medium
// for every enconter of one, we will add the count of ones to the answer. 
class Solution {
public:
    int maxOperations(string s) {
        
        int n = s.length();
        int count=0;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='1')
            {
                count++;
            }
            else
            {
                while((i+1)<n && s[i+1]=='0')
                {
                    i++;
                }
                ans+=count;
            }
        }
        return ans;
    }
};

// time complexity: O(n)
// space complexity: O(1)
