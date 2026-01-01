// level: Medium
// problem statement:Given a string consisting of digits from 2 to 9 (inclusive). Return all possible letter combinations that the number can represent.

// solution:
class Solution {
public:
    void findCombination(int ind, string curr, string& digits, unordered_map<int,string>& mp,vector<string>& res)
    {
        if(ind==digits.size())
        {
            res.push_back(curr);
        }

        for(char ch: mp[digits[ind]-'0'])
        {
            findCombination(ind+1,curr+ch, digits,mp,res);
        }
    }
    vector<string> letterCombinations(string digits) {
        
        unordered_map<int,string> mp={
            {2,"abc"},{3,"def"},{4,"ghi"},{5,"jkl"},{6,"mno"},{7,"pqrs"},{8,"tuv"},{9,"wxyz"}
        };
        vector<string> res;
        string curr="";
        findCombination(0,curr,digits,mp,res);
        return res;

    }
};

// time complexity: (n*(4^n))
// space complexity: O(n) (recursive stack space) + O(n*(4^n))
