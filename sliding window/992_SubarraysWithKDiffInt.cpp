class Solution {
private:
    int solve(vector<int>&nums, int k)
    {
        int i = 0, j = 0;
        int count;
        int ans = 0;
        unordered_map<int, int>mp;

        while(j<nums.size())
        {   
            mp[nums[j]]++;
            while(mp.size() > k)
            {
                mp[nums[i]]--;
                if(mp[nums[i]] == 0)
                {
                    mp.erase(nums[i]);
                }
                i++;
            }

            ans += j-i+1;
            j++;
        }
        return ans;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {

        int a = solve(nums, k);
        int b = solve(nums, k-1);
        return a - b;
        
    }
};