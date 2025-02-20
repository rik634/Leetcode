//level:medium
//link: https://leetcode.com/problems/find-unique-binary-string/description/
//solution

class Solution {
public:
    int n;
    unordered_set<string> s;
    string generate(string curr)
    {
        if(curr.size()==n)
        {
            if(s.find(curr)==s.end())
            {
                return curr;
            }
            return "";
        }
        string addZero = generate(curr+"0");
        if(addZero.size()>0)
        {
            return addZero;
        }
        return generate(curr+"1");
    }
    string findDifferentBinaryString(vector<string>& nums) {
        
        n= nums.size();
        for(string str:nums)
        {
            s.insert(str);
        }
        return generate("");
    }
};
