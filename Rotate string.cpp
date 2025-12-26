// level: easy
// problem statement:

// brute force
class Solution {
public:
    bool rotateString(string s, string goal) {
        
        int n = s.length();
        if(s.length()!=goal.length())
        {
            return false;
        }
        for(int i=0;i<n;i++)
        {
            string rotated = s.substr(i)+s.substr(0,i);
            if(rotated==goal)
            {
                return true;
            }
        }
        return false;
    }
};
// time complexity: O(n(n+n+n) since generating N rotations and each comparison takes O(N) time.( (O(n) = for sustring generation, O(n)= for adding thise substrings, O(n)=for comparing the 2 strings)
// space complexity:O(1)

// optimized
class Solution {
public:
    bool rotateString(string s, string goal) {
        
        int n = s.length();
        if(s.length()!=goal.length())
        {
            return false;
        }
        string doubled = s + s;
        if(doubled.find(goal)==string::npos)
        {
            return false;
        }
        return true;

    }
};
// time complexity: O(N) (find operation in doubled string)
// space complexity: O(n) (string length)
