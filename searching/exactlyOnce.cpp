class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0;
        int h = nums.size()-1;
        int m;
        while(l<h)
        {
            m = (l+h)/2;
            if(m%2 == 1)
            {
                m--;
            }
            if(nums[m] != nums[m+1])
            {
                h = m;
            }
            else
            {
                l = m+2;
            }
        }
        return nums[l];
        
    }
};