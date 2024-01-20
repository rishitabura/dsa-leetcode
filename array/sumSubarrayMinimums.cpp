#include <bits/stdc++.h>
#include <vector>
using namespace std;

// O(n^3)
//  void subarray(vector<int> arr)
//  {
//      int n = arr.size();
//      int sum = 0;
//      for (int i = 0; i < n; i++)
//      {
//          int mini = INT_MAX;
//          for (int j = i; j < n; j++)
//          {
//              for (int k = i; k <= j; k++)
//              {
//                  mini = min(arr[k], mini);
//                  // cout << "[" << arr[k] << "]";
//              }
//              sum += mini;
//              // cout << endl << mini;
//              // cout << endl;
//          }
//          // cout << sum<< endl;
//      }
//          cout << sum<< endl;

// }

// O(n^2)
void subarray(vector<int> arr)
{
    int n = arr.size();
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        int mini = INT_MAX;
        for (int j = i; j < n; j++)
        {
            mini = min(mini, arr[j]);
            sum += mini;
        }
    }
    cout << sum << endl;
}

vector<int> getNSL(vector<int> &arr, int n)
{
    vector<int> nsl(n);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        if (st.empty())
        {
            nsl[i] = -1;
        }
        else
        {
            while (!st.empty() && arr[st.top()] >= arr[i])
            {
                st.pop();
            }
            nsl[i] = st.empty() ? -1 : st.top();
        }
        st.push(i);
    }

    return nsl;
}

vector<int> getNSR(vector<int> &arr, int n)
{
    vector<int> nsr(n);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--)
    {
        if (st.empty())
        {
            nsr[i] = n;
        }
        else
        {
            while (!st.empty() && arr[st.top()] > arr[i])
            {
                st.pop();
            }
            nsr[i] = st.empty() ? n : st.top();
        }
        st.push(i);
    }

    return nsr;
}
int sumSubarrayMins(vector<int> &arr)
{

    int n = arr.size();
    vector<int> nsl = getNSL(arr, n);
    vector<int> nsr = getNSR(arr, n);

    long long sum = 0;
    int mod = 1e9 + 7;

    for (int i = 0; i < n; i++)
    {
        long long ls = i - nsl[i];
        long long rs = nsr[i] - i;

        long long totalWays = ls * rs;

        long long totalSum = arr[i] * totalWays;

        sum = (sum + totalSum) % mod;
    }

    return sum;
}

int main()
{
    vector<int> arr = {11, 81, 94, 43, 3};
    subarray(arr);
    return 0;
}