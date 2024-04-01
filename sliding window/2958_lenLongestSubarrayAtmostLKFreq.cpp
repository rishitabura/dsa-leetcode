/*Length of Longest Subarray With at Most K Frequency*/

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int>mp;
        int i = 0;
        int j = 0;
        int ans = 0;
        while(j<n)
        {
            mp[nums[j]]++;

            if(mp[nums[j]] > k)
            {
                while(nums[i] != nums[j])
                {
                    mp[nums[i]]--;
                    i++;
                }
                mp[nums[i]]--;
                i++;
            }
            ans = max(ans, j-i+1);
            j++;
        }
        return ans;
    }
};