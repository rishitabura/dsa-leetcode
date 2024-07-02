// #include<bits/stdc++.h>
// #include<vector>
// using namespace std;

// void sumSubets(int wt[], int n, int ind, int target, vector<int>&ans)
// {
//     if (target == 0)
//     {
//         cout << "[";
//         for (int i = 0; i < ans.size(); i++)
//         {
//             cout << ans[i] << " ";
//         }
//         cout << "]";
//         return;
        
//     }
    
//     if (ind == n)
//     {
//         return;
//     }

//     // exclude
//     sumSubets(wt, n, ind+1, target, ans);

//     if (wt[ind] <= target)
//     {
//         ans.push_back(wt[ind]);
//         sumSubets(wt, n, ind+1, target-wt[ind], ans);
//         ans.pop_back();
//     }
    
// }

// int main()
// {
//     int wt[] = {5,10,12,13,15,18};
//     int n = 6;
//     int target = 30;
//     vector<int>ans;
//     sumSubets(wt,n,0,target,ans);
//     return 0;
// }

#include<bits/stdc++.h>
#include<vector>
using namespace std;

bool sumSubets(int wt[], int n, int ind, int target, vector<int>&ans)
{
    if (target == 0)
    {
        cout << "[";
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << "]";
        return true;
        
    }
    
    if (ind == n)
    {
        return false;
    }

    // exclude
    if(sumSubets(wt, n, ind+1, target, ans))
    {
        return true;
    }

    if (wt[ind] <= target)
    {
        ans.push_back(wt[ind]);
        if(sumSubets(wt, n, ind+1, target-wt[ind], ans))
        {
            return true;
        }
        ans.pop_back();
    }
    return false;
    
}

int main()
{
    int wt[] = {5,10,12,13,15,18};
    int n = 6;
    int target = 30;
    vector<int>ans;
    if(!sumSubets(wt,n,0,target,ans))
    {
        cout << "Not found";
    }
    return 0;
}