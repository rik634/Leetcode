// Level: medium
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        
        if(numerator==0)
        {
            return "0";
        }
        string fraction;
        if((numerator<0) ^(denominator<0))
        {
            fraction="-";
        }
        long long dividend = abs((long long) numerator);
        long long divisor = abs((long long) denominator);
        fraction+=to_string(dividend/divisor);
        long long rem = dividend%divisor;
        if(rem==0)
        {
            return fraction;
        }
        fraction+=".";
        unordered_map<long long,int> mp;
        while(rem!=0)
        {
            if(mp.count(rem))
            {
                fraction.insert(mp[rem],"(");
                fraction+=")";
                break;
            }

            mp[rem]=fraction.size();
            rem=rem*10;
            fraction+= to_string(rem/divisor);
            rem = rem % divisor;
        }
        return fraction;
    }
};
// time complexity: O(D)
// space complexity: O(D+logD)
