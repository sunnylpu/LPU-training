#include <bits/stdc++.h>
using namespace std;

void abc(char s[])
{
    if (s[0] == '\0')
        return;

    abc(s + 1);
    abc(s + 1);
    cout << s[0];
}

int fun(int count)
{
    cout << count << endl;
    if (count < 3)
    {
        fun(fun(fun(++count)));
    }
    return count;
}
void sortarr(vector<int> &arr, int l, int r)
{
    if (r < l)
        return;
    int mn = INT_MAX, mnidx = -1;
    for (int i = l; i <= r; i++)
    {
        if (arr[i] <= mn)
        {
            mn = arr[i];
            mnidx = i;
        }
    }
    swap(arr[mnidx], arr[l]);
    sortarr(arr, l + 1, r);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    // abc("xyz");
    // fun(1);
    vector<int> arr{5, 4, 45, 2, 1};
    sortarr(arr, 0, arr.size() - 1);
    for (auto x : arr)
        cout << x << " ";
    return 0;
}
// factorial of a large number
// User function template for C++

class Solution
{
public:
    vector<int> factorial(int n)
    {
        // code here
        if (n == 1)
            return {1}; // base case
        // induction step
        vector<int> res = factorial(n - 1);
        int carry = 0;
        // hypothesis
        for (int i = res.size() - 1; i >= 0; i--)
        {
            int temp = res[i] * n + carry;
            res[i] = (temp) % 10;
            carry = temp / 10;
        }
        while (carry > 0)
        {
            res.insert(res.begin(), carry % 10);
            carry = carry / 10;
        }
        return res;
    }
};
// using reverse
// User function template for C++

class Solution
{
public:
    vector<int> factorial(int n)
    {
        // code here
        auto res = helper(n);
        reverse(res.begin(), res.end());
        return res;
    }
    vector<int> helper(int n)
    {
        if (n == 1)
            return {1}; // base case
        // induction step
        vector<int> res = helper(n - 1);
        // reversed
        int carry = 0;
        // hypothesis
        for (int i = 0; i < res.size(); i++)
        {
            int temp = res[i] * n + carry;
            res[i] = (temp) % 10;
            carry = temp / 10;
        }
        while (carry > 0)
        {
            res.push_back(carry % 10);
            carry = carry / 10;
        }
        return res;
    }
};