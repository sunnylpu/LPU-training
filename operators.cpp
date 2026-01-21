#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    // vector<int> v({a, b, c});
    // sort(v.begin(), v. end());/
    int arr[] = {a, b, c};
    sort(arr, arr + 3);
    if (arr[0] + arr[1] > arr[2])
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}