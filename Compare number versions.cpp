// Level: Medium
class Solution {
public:
    int compareVersion(string version1, string version2) {
        
        int i=0;
        int j=0;
        int n1 = version1.length();
        int n2 = version2.length();
        int n = max(n1,n2);
        while(i<n1 || j<n2)
        {
            int v1=0;
            int v2=0;
            while(i<n1 && version1[i]!='.')
            {
                v1 = v1*10 + (version1[i]-'0');
                i++;
            }
            while(j<n2 && version2[j]!='.')
            {
                v2 = v2*10 + (version2[j]-'0');
                j++;
            }
            if(v1<v2)
            {
                return -1;
            }
            if(v1>v2)
            {
                return 1;
            }
            i++;
            j++;
        }
        return 0;
    }
};
// time complexity: O(n+m)
// space complexity: O(1)
