#include <bits/stdc++.h>
#include <vector>
#include <unordered_map>
using namespace std;

bool comp(pair<char, int> a, pair<char, int> b)
{
    return a.second > b.second;
}

string frequencySort(string &s)
{
    unordered_map<char, int> freq;

    for (int i = 0; i < s.size(); i++)
    {
        freq[s[i]]++;
    }

    vector<pair<char, int>> v;
    for (auto x : freq)
    {
        v.push_back(make_pair(x.first, x.second));
    }
    sort(v.begin(), v.end(), comp);

    // for (auto it : v)
    // {
    //     cout <<it.first << " " << it.second << endl;
    // }

    string res;

    for (int i = 0; i < v.size(); i++)
    {
        res.append(v[i].second, v[i].first);
    }

    return res;
}

// string frequencySort(string s)
// {
//     return solve(s);
// }

int main()
{
    string str = "tree";
    cout << frequencySort(str);

    return 0;
}