#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void segregate(int *a, int n)
{
    // quick sort method
    // int i = 0, j = 1;

    // while(j < n)
    // {
    //     if(a[i] > 0)
    //     {
    //         if(a[j] < 0)
    //         {
    //             swap(a[i], a[j]);
    //             i++;
    //         }
    //     }
    //     else
    //         i++;

    //     j++;
    // }

    //two pointer method 
    int i = 0, j = n - 1;

    while(i < j)
    {
        if(a[i] < 0)
            i++;
        
        if(a[j] > 0)
            j--;
        
        if(a[i] > 0 and a[j] < 0)
        {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
}

void display(int *a, int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    cout << endl;
}

int main()
{
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    segregate(a, n);
    display(a, n);
}
