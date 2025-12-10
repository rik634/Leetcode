// level: Medium
class Solution {
public:
    long long maxPoints(vector<int>& technique1, vector<int>& technique2, int k) {

        int n = technique1.size();
        vector<int> prev(n+1,0);

        for(int i=1;i<=n;i++){

            vector<int >temp(n+1,0);
            temp[0]=prev[0]+technique2[i-1];
            for(int j=1;j<=i;j++){
                if(i==1 && j==1)
                {
                    temp[j]=technique1[i-1];
                    continue;
                }
                if(j==i)
                {
                    temp[j]=prev[i-1]+technique1[i-1];
                    continue;
                }
                temp[j]=max(prev[j-1]+technique1[i-1],prev[j]+technique2[i-1]);
            }
            prev=temp;
            
        }
        int mx=0;
        for(int j=k;j<=n;j++){
            mx=max(mx,prev[j]);
        }
        return (long long)mx;
    }
};
// time complexity: O(n*n)
// space complexity: O(2*n)

// using greedy
class Solution {
public:
    long long maxPoints(vector<int>& technique1, vector<int>& technique2, int k) {
        
        int count=0;
        int n = technique1.size();
        vector<long long> cost;
        long long sum=0;
        for(int i=0;i<n;i++)
        {
            if(technique1[i]>=technique2[i])
            {
                sum+=technique1[i];
                count++;
            }
            else
            {
                sum+=technique2[i];
                cost.push_back(technique1[i]-technique2[i]);
            }
        }
        if(count>=k)
        {
            return sum;
        }
        sort(cost.begin(),cost.end());
        int ind=cost.size()-1;
        while(count<k && ind>=0)
        {
            sum+=cost[ind];
            ind--;
            count++;
        }
        return sum;
    }
};
// time complexity: O(nlogn(
// space complexity: O(n)
