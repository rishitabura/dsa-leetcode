/*Count Subarrays Where Max Element Appears at Least K Times*/

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        
        long long i = 0, j = 0;
        long long ans = 0;
        long long maxi = *max_element(nums.begin(), nums.end());
        int count = 0;
        while(j < nums.size() || i>j)
        {
            if(nums[j] == maxi)
            {
                count++;
            }
            while(count >= k)
            {
                if(nums[i] == maxi)
                {
                    count--;
                }
                i++;
                ans += nums.size() - j;
                cout << j << " " << ans << endl;
            }
            j++;
        }
        return ans;
    }
};