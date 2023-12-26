class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int el;
        int n = nums.size();
        for(int i=0;i<nums.size();i++)
        {
            if(count==0)
            {
                count =1;
                el = nums[i];
            }
            else if(el == nums[i])
            {
                count++;
            }
            else
            {
                count--;
            }
        }

        int count1=0;
        for(int i=0;i<nums.size();i++)
        {
            if(el == nums[i])
            {
                count1++;
            }
        }
        if(count1>n/2)
        {
            return el;
        }
        else
        {
            return -1;
        }
        
    }
};