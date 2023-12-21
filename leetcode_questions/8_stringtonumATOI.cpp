#include <iostream>
#include <typeinfo>
using namespace std;

int stringtoint(string s)
{
    int n = s.length();
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        res = res*10+ s[i]-'0';
    }
    return res;
    

}
int main()
{
    string s = "34567";
    int r = stringtoint(s);
    cout << typeid(r).name();
    
    return 0;
}
