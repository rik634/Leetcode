// level:easy
// problem statement: Roman numerals are represented by seven different symbols: I = 1, V = 5, X = 10, L = 50, C = 100, D = 500, M = 1000
//For example: 2 is written as II, 12 is written as XII, 27 is written as XXVII.
//Roman numerals are usually written largest to smallest from left to right. But in six special cases, subtraction is used instead of addition:
//I before V or X → 4 and 9,
//X before L or C → 40 and 90,
//C before D or M → 400 and 900
//Given a Roman numeral, convert it to an integer.

// brute force
class Solution {
public:
    int romanToInt(string s) {
        
        int n = s.length();
        int num=0;
        char prev;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='I'){
                if(prev=='V' || prev=='X'){
                    num-=1;
                }else{
                    num+=1;
                }
            }else if(s[i]=='V'){
                num+=5;
            }else if(s[i]=='X'){
                if(prev=='L' || prev=='C'){
                    num-=10;
                }else{
                    num+=10;
                }
            }else if(s[i]=='L'){
                num+=50;
            } else if(s[i]=='C'){
                if(prev=='D' || prev=='M'){
                    num-=100;
                }else{
                    num+=100;
                }
            }else if(s[i]=='D'){
                num+=500;
            }else if(s[i]=='M'){
                num+=1000;
            }
            prev=s[i];
        }
        return num;
    }
};
// time complexity:O(n)
// space complexity;O(1)

// better approach (hash)
class Solution {
public:
    int romanToInt(string s) {
        
        int n = s.length();
        int num=0;
        unordered_map<char,int> mp={{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        for(int i=0;i<n-1;i++)
        {
            if(mp[s[i]]<mp[s[i+1]])
            {
                num-=mp[s[i]];
            }
            else
            {
                num+=mp[s[i]];
            }
        }
        num+=mp[s[n-1]];
        return num;
    }
};
// time complexity:O(n)
// space complexity:O(1)
