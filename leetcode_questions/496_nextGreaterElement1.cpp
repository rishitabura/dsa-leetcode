#include <bits/stdc++.h>
#include <vector>
using namespace std;

vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    stack<int> st;
    int n1 = nums1.size();
    int n2 = nums2.size();
    vector<int> nge(n1,-1);
    int j = 0;
    for (int i = 2*n2-1; i >= 0; i--)
    {

        while (!st.empty() && st.top() <= nums1[j]) 
        {
            st.pop();
        }
        if(i)
        
    }
    
}

int main()
{

    return 0;
}