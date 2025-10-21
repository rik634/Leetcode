// level:Medium
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        
        sort(nums.begin(),nums.end());
        int count=0;
        unordered_map<int,int> mp;
        int index=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=nums[index])
            {
                mp[nums[index]]=i-index;
                count=max(count,i-index);
                index=i;
            }
        }
        mp[nums[index]]=nums.size()-index;
        count=max(count,(int)nums.size()-index);
        auto leftBound = [&](int value){
            int left=0;
            int right=nums.size()-1;
            while(left<right)
            {
                int mid = (left+right)/2;
                if(nums[mid]<value)
                {
                   left=mid+1;
                }
                else
                {
                   right=mid;
                }
            }
            return left;
        };
        
        auto rightBound =[&](int value){
            int left=0;
            int right=nums.size()-1;
            while(left<right)
            {
                int mid = (left+right+1)/2;
                if(nums[mid]>value)
                {
                    right = mid-1;
                }
                else
                {
                    left=mid;
                }
            }
            return left;
        };

        for(int i=nums.front();i<=nums.back();i++)
        {
            int l = leftBound(i-k);
            int r = rightBound(i+k);
            int temp;
            if(mp.count(i))
            {
                temp = min(r-l+1,mp[i]+numOperations);
            }
            else
            {
                temp = min(r-l+1,numOperations);
            }
            count=max(count,temp);
        }
        return count;

    }
};

// time complexity: O(max(nlogn,klogn));
// space complexity: O(n)
