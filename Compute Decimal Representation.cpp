// Level: Easy
class Solution {
public:
    vector<int> decimalRepresentation(int n) {

        vector<int> res;
        long long f=1;
        while(n>0){
            int rem = n%10;
            if(rem*f!=0)
            {
                res.push_back(rem*f);
            }
            f=f*10;
            n=n/10;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};©leetcode
// time complexity: O(n) (reverse) + O(logn) (base 10)
// space complexity: O(n)
