/*rCheck if Array Is Sorted 
time - O(n)*/
#include<bits/stdc++.h>
#include<vector>
using namespace std;

int isSorted(int n, vector<int> a) {

    // for(int i = 1; i<n ; i++)
    // {
    //     if(a[i] < a[i-1])
    //     {
    //         return 0;
    //     }
    // }
    // return 1;

    int start = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] < start)
        {
            return 0;
        }
        start = a[i];
    }
    return 1;
    
}


int main()
{
    vector<int> a = {1,2,3,4};
    int n = a.size();
    cout << isSorted(n,a);
    
    return 0;
}