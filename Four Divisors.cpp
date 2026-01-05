// level: Medium
// problem statement:

// brute force: (Enumeration)
class Solution {
public:
    int hasFourDivisor(int num)
    {
        int count=0;
        int s=0;
        for(int i=1;i*i<=num;i++)
        {
            if(num%i==0)
            {
                count++;
                s+=i;
                if(i!=(num/i))
                {
                    count++;
                    s+=(num/i);
                }
            }
        }
        return count==4 ? s : -1;
    }
    int sumFourDivisors(vector<int>& nums) {
        
        int n = nums.size();
        int sum=0;
        for(int i=0;i<n;i++)
        {
           int val=hasFourDivisor(nums[i]);
           if(val!=-1)
           {
             sum+=val;
           }
        }
        return sum;
    }
};
// time complexity: O(N*sqrt(C)) (N= length of array, C= range of elements in array)
// space complexity: O(1)

// optimized (Pre-processing)
class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        
        int C=100000,C3=46;
        int n = nums.size();
        vector<int> isprime(C+1,1);
        vector<int> primes;
        for(int i=2;i<=C;i++)
        {
            if(isprime[i])
            {
                primes.push_back(i);
            }
            for(int j=i+i;j<=C;j+=i)
            {
                isprime[j]=0;
            }
        }

        unordered_map<int,int> factor4;
        for(int prime: primes)
        {
            if(prime<=C3){
                factor4[prime*prime*prime] = 1 + prime+ prime*prime + prime*prime*prime;
            }
        }
        for(int i=0;i<primes.size();i++)
        {
            for(int j=i+1;j<primes.size();j++)
            {
                if(primes[i]<=C/primes[j])
                {
                    factor4[primes[i]*primes[j]]=1+primes[i]+primes[j]+primes[i]*primes[j];
                }
                else
                {
                    break;
                }
            }
        }
        int sum=0;
        for(auto it:nums)
        {
            sum+=factor4[it];
        }
        return sum;
    }
};
// Time complexity: 
// 1. O(pi*pi*C) (=(O(pi*pi*C) + O(pi*pi*C^(1/3)), constructing all four-factor numbers using the prime table ) + O(CloglogC) (Sieve of Eratosthenes ALGORITHM) + O(n) (traversing all elements in the array nums) = o(pi*pi*C) + O(CloglogC) + O(N)
// 2. O(pi*pi*C) (constructing all four-factor numbers using the prime table ) + O(C) (Sieve of  Euler ALGORITHM) + O(n) (traversing all elements in the array nums) = o(pi*pi*C) + O(C) + O(N)

// space complexity: O(C+pi*C) (n array of length C is required to record whether each number is prime, and an array of length π(C) is required to store all the primes.)
