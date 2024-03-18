/*using sorting
tc- O(nlogn)
sc - O(1)*/
class Solution
{
public:
    int maxOperations(vector<int> &nums, int k)
    {

        sort(nums.begin(), nums.end());
        int i = 0;
        int j = nums.size() - 1;
        int op = 0;
        while (i < j)
        {
            int sum = nums[i] + nums[j];
            cout << sum << endl;
            if (sum == k)
            {
                op++;
                i++;
                j--;
            }
            else if (sum < k)
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return op;
    }
};

/*using map
tc - O(n)
sc - O(n)*/
class Solution
{
public:
    int maxOperations(vector<int> &nums, int k)
    {

        int op = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            if (mp[k - nums[i]] > 0)
            {
                op++;
                mp[k - nums[i]]--;
            }
            else
            {
                mp[nums[i]]++;
            }
        }
        return op;
    }
};