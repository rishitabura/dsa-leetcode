#include <bits/stdc++.h>
#include <vector>
using namespace std;

bool isVowel(char ch)
{
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
        ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
    {
        return true;
    }
    return false;
}
bool halvesAreAlike(string s)
{

    int r = s.size() - 1;
    int l = 0;
    int lc = 0;
    int rc = 0;
    while (l < r)
    {
        if (isVowel(s[l]))
        {
            lc++;
            l++;
        }
        else
        {
            l++;
        }
        if (isVowel(s[r]))
        {
            rc++;
            r--;
        }
        else
        {
            r--;
        }
    }
    if (lc == rc)
        return true;
    return false;
}
// bool halvesAreAlike(string s)
// {

//     int half = s.size() / 2;
//     int i = 0;
//     string s1 = "";
//     string s2 = "";

//     while (i > half)
//     {
//         s1 = s[i];
//         i++;
//     }
//     for (int i = 0; i < half; i++)
//     {
//         s1[i] = s[i];
//         s2[i] = s[i + half];
//     }

//     int count = 0;
//     for (int i = 0; i < half; i++)
//     {
//         if (isVowel(s1[i]))
//         {
//             count++;
//         }
//     }
//     for (int i = 0; i < half; i++)
//     {
//         if (isVowel(s2[i]))
//         {
//             count--;
//         }
//     }

//     if (count == 0)
//     {
//         return true;
//     }
//     return false;
// }

int main()
{
    string s = "book";

    cout << halvesAreAlike(s);

    return 0;
}