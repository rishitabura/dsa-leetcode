class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {

        int n = nums.size();
        sort(nums.begin(),nums.end());
        long long currSum=0;
        long long maxi = 0;
        long long ans = 0;
        for(int i = 0; i<n; i++)
        {
            if(currSum > nums[i])
            {
                ans = currSum + nums[i];
                maxi = max(ans, maxi);
            }
            currSum += nums[i];
            
        }
        return (maxi > 0) ? maxi : -1 ;
    }
};