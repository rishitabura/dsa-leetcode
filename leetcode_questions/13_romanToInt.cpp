class Solution {
public:
    unordered_map<char, int> mp;

    int convert(string& s) {
        int number = 0;
        int n = s.size();
        for (int i = 0; i < n - 1; i++) {
            if (mp[s[i]] < mp[s[i + 1]]) {
                number += (-mp[s[i]]);
            } else {
                number += mp[s[i]];
            }
        }
        number += mp[s[n-1]];
        return number;
    }
    int romanToInt(string s) {
        mp.insert({'I', 1});
        mp.insert({'V', 5});
        mp.insert({'X', 10});
        mp.insert({'L', 50});
        mp.insert({'C', 100});
        mp.insert({'D', 500});
        mp.insert({'M', 1000});

        return convert(s);
    }
};