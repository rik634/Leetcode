// level: Medium
// sort + greedy
class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        
        sort(happiness.begin(),happiness.end(),greater<int>());
        long long sum=0;
        int count=0;
        int n = happiness.size();
        for(int i=0;i<k;i++)
        {
            sum+=max(happiness[i]-count,0);
            count++;

        }
        return sum;
    }
};
// time complexity: O(nlogn) + O(k)
// space complexity: O(1)

// heap + greedy
class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        
        priority_queue<int> pq(happiness.begin(),happiness.end());
        long long sum=0;
        int count=0;
        for(int i=0;i<k;i++)
        {
            auto p = pq.top();
            pq.pop();
            sum+=max(p-count,0);
            count++;
        }
        return sum;
    }
};
// time complexity: O(nlogn+klogn)
// space complexity: O(n)
// push and pop in priority queue takes O(logn)
