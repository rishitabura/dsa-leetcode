#include <bits/stdc++.h>
#include <vector>
#include <unordered_map>
using namespace std;

vector<vector<int>> findWinners(vector<vector<int>> &matches)
{
    vector<vector<int>> result;

    unordered_map<int, int> lost;

    for (int i = 0; i < matches.size(); i++)
    {
        int lose = matches[i][1];
        lost[lose]++;
    }
    vector<int> ans1;
    vector<int> ans2;

    for (int i = 0; i < matches.size(); i++)
    {
        int winner = matches[i][0];
        int loser = matches[i][1];

        if (lost.find(winner) == lost.end())
        {
            ans1.push_back(winner);
            lost[winner] = -1;
        }
        if (lost[loser] == 1)
        {
            ans2.push_back(loser);
        }
    }

    sort(ans1.begin(), ans1.end());
    sort(ans2.begin(), ans2.end());

    result.push_back(ans1);
    result.push_back(ans2);

    return result;
}
// vector<vector<int>> result;

// vector<int> lost( matches.size(), 0);
// for (int i = 0; i < matches.size(); i++) {
//     for (int j = 1; j < matches[0].size(); j++) {
//         lost[matches[i][j] - 1]++;
//     }
// }
// vector<int> ans1;
// for (int i = 0; i < lost.size(); i++) {
//     if (lost[i] == 0) {
//         ans1.push_back(i + 1);
//     }
// }
// vector<int> ans2;
// for (int i = 0; i < lost.size(); i++) {
//     if (lost[i] == 1) {
//         ans2.push_back(i + 1);
//     }
// }

// result.push_back(ans1);
// result.push_back(ans2);

// return result;

int main()
{
    vector<vector<int>> matches = {{1, 3}, {2, 3}, {3, 6}, {5, 6}, {5, 7}, {4, 5}, {4, 8}, {4, 9}, {10, 4}, {10, 9}};
    // vector<vector<int>> matches = {{2, 3}, {1, 3}, {5, 4}, {6, 4}};
    vector<vector<int>> result = findWinners(matches);

    for (auto it : result)
    {
        cout << "[";
        for (auto s : it)
        {
            cout << s << " ";
        }
        cout << "]";
    }

    return 0;
}