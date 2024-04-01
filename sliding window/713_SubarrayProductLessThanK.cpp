/*Subarray Product Less Than K*/

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {

        if(k <= 1)
        {
            return 0;
        }

        int n = nums.size();
        int i = 0, j = 0;
        int product = 1;
        int result = 0;
        while(j< n)
        {
            product *= nums[j];
            
            while(product >= k)
            {
                product /= nums[i];
                i++;
            }
            result += (j-i+1);
            j++;
        }
        return result;
    }
};