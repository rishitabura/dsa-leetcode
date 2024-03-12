class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {

        unordered_map<int, int> mp;
        int maxVal = INT_MIN;
        for(int i = 0; i<nums.size(); i++)
        {
            mp[nums[i]]++;
            maxVal = max(maxVal, mp[nums[i]]);
        }
        
        int count = 0;
        // for(auto it: mp)
        // {
        //     maxVal = max(maxVal, it.second);
        // }
        for(auto m : mp)
        {
            if(m.second == maxVal){
                count++;
            }
        }
        
        return count * maxVal;
    }
};