/*Count Subarrays With Fixed Bounds*/
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
    
        int i = 0, j = 0;
        long long count  = 0;
        int l = -1 , r = -1;

        while(j < nums.size())
        {
            // out of range
            if(minK > nums[j] || maxK < nums[j])
            {
                i = j+1;
            }

            if(nums[j] == minK)
            {
                l = j;
            }
            if(nums[j] == maxK)
            {
                r = j;
            }

            count += max(0, (min(l,r) - i+1));
            j++;
        }
        return count;
    }
};