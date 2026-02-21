// level: Easy
class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        
        int total = accumulate(apple.begin(),apple.end(),0);
        priority_queue<int> pq(capacity.begin(),capacity.end());

        int count=0;
        while(total>0 && !pq.empty())
        {
            auto p = pq.top();
            pq.pop();
            total-=min(total,p);
            count++;
        }
        return count;
    }
};

// time complexity: O(n) + O(m)  = O(n+m)
// space complexity: O(m)

class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int total = accumulate(apple.begin(),apple.end(),0);
       sort(capacity.begin(),capacity.end(),greater<int>());

        int count=0;
        int ind=0;
        while(total>0 )
        {
            
            total-=min(total,capacity[count]);
            count++;
        }
        return count;
    }
};
// time complexity: O(n+mlogm)
// space complexity: O(m)
