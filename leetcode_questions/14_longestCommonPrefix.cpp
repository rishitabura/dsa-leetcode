#include<bits/stdc++.h>
#include<vector>
using namespace std;

// class Solution {
// public:
//     string longestCommonPrefix(vector<string>& strs) {

//         if(strs.empty()) return "";

//         string prefix = strs[0];
//         for(string s : strs)
//         {
//             while(s.find(prefix) != 0)
//             {
//                 prefix = prefix.substr(0,prefix.length()-1);
//             }
//         }

//         return prefix;

//     }
// };

string longestCommonPrefix(vector<string> &strs)
{

    if (strs.empty())
        return "";

    string prefix = "";

    for (int i = 0; i < strs[0].length(); i++)
    {
        // 1st string traversing
        char ch = strs[0][i];
        bool match = true;

        for (int j = 1; j < strs.size(); j++)
        {
            if (ch != strs[j][i])
            {
                match = false;
                break;
            }
        }

        if (match == false)
        {
            break;
        }
        else
        {
            prefix.push_back(ch);
        }
    }

    return prefix;
}

int main()
{
    vector<string> strs = {"flower","flow","flight"};
    cout <<  longestCommonPrefix(strs);
    
    return 0;
}
