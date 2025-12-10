// level:Medium
class Solution {
public:
    bool isPrime(string s) {

        int n = stoi(s);
         if (n <= 1) return false;
        if (n <= 3) return true;
    
    if (n % 2 == 0 || n % 3 == 0) return false;
    
    // Check up to sqrt(n)
    for (int i = 5; i * i <= n; i = i + 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    
    return true;
}
    bool completePrime(int num) {
        
        int nm = to_string(num).length();
        string str=to_string(num);
        string prefix="";
        string suffix="";
        for(int i=0,j=nm-1;i<nm && j>=0;i++,j--)
        {
            prefix+=str[i];
            suffix=str[j]+suffix;
            if(!isPrime(prefix))
            {
                return false;
            }
            if(!isPrime(suffix))
            {
                return false;
            }
        }
        return true;

    }
};

// Time complexity: O(n*sqrt(n))
// space complexity: O(N)
