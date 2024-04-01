/*tc- O(n)
sc - O(1)*/
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {

        vector<int> ans;
        for(int i = 0; i<nums.size(); ++i)
        {
            int a = abs(nums[i]) -1 ;
            if(nums[a] < 0)
            {
                ans.push_back(a+1);
            }
            else
            {
                nums[a] = -nums[a];
            }
        }
        return ans;
        
    }
};