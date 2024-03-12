// using set
// tc - O(n1+n2) + O(n) sc - O(n) 

vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
{

    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    int i = 0, j = 0;
    unordered_set<int> st;
    vector<int> result;
    while (i < nums1.size() && j < nums2.size())
    {
        if (nums1[i] == nums2[j])
        {
            st.insert(nums1[i]);
            i++;
            j++;
        }
        else if (nums1[i] < nums2[j])
        {
            i++;
        }
        else if (nums1[i] > nums2[j])
        {
            j++;
        }
    }

    for (auto it : st)
    {
        result.push_back(it);
    }
    return result;
}

// using map 
// tc - O(n1+n2) sc - O(n1)
vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
{

    int i = 0, j = 0;
    vector<int> result;
    unordered_map<int, int> mp;
    for (auto &it : nums1)
    {
        mp[it]++;
    }
    for (auto &it : nums2)
    {
        if (mp.find(it) != mp.end())
        {
            result.push_back(it);
            mp.erase(it);
        }
    }

    return result;
}