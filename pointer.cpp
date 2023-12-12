#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main()
{
    // int a = 10;
    // int *aptr;
    // aptr = &a;

    // cout << a<< endl;
    // cout << aptr << endl;
    // cout << &a << endl;
    // cout << *aptr<< endl;

    // aptr++;
    // cout << aptr<< endl;


    // int arr[] = {10,20,30};
    // cout << *arr << endl; 

    // int *ptr = arr;
    // for (int i = 0; i < 3; i++)
    // {
    //     cout << *ptr << endl;
    //     ptr++;
    // }


    int b = 12;
    int *p = &b;
    int **q = &p;

    cout << p << endl;
    cout << *p << endl;
    cout << q << endl;
    cout << *q << endl;
    cout << **q << endl;
    

    return 0;
}