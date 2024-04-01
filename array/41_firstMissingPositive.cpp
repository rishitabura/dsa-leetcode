/*sc - O(n)*/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        int n = nums.size();
        unordered_map<int, int> mp;
        for(int i =0 ; i<nums.size(); i++)
        {
            if(nums[i] > 0)
                mp[nums[i]]++;
        }
        for(auto it : mp)
        {
            cout << it.first << " " << it.second << endl;
        }
        int i = 1 ;
       
        for( i = 1; i<n+1; i++)
        {
            if(mp.find(i) == mp.end())
            {
                return i;
            }
        }
        return i;
        
    }
};

/*tc - O(n)
sc - O(1)*/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {

        int n = nums.size();
        nums.push_back(0);
        for (int i = 0; i < n; ++i) {
            while (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i]])
                swap(nums[i], nums[nums[i]]);
        }

        for (int i = 1; i <= n; i++) {
            if(nums[i] != i)
            {
                return i;
            }
        }
        return n+1;
    }
};