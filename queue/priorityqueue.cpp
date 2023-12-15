#include<bits/stdc++.h>
#include<queue>
using namespace std;

int main()
{
    int arr[] = {57,23,8,75,12,54};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Original array : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    //  max heap
    priority_queue<int> q;

    for (int i = 0; i < n; i++)
    {
        q.push(arr[i]);
    }
    cout << "\nPriority queue (Max heap) : " ;
    while (!q.empty())
    {
        cout << q.top() << " ";
        q.pop();
    }

    // min heap
    priority_queue<int, vector<int>, greater<int>> p;
    for (int i = 0; i < n; i++)
    {
        p.push(arr[i]);
    }
    cout << "\nPriority queue (Min heap) : " ;
    while (!p.empty())
    {
        cout << p.top() << " ";
        p.pop();
    }
    
    
    


    return 0;
}