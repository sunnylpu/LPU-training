#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
class Solution
{
public:
    bool check(string s, int l, int r)
    {
        if (l == r)
            return true;
        while (l < r && s[l] == s[r])
        {
            l++, r--;
        }
        if (l >= r)
            return true;
        return false;
    }
    bool validPalindrome(string s)
    {
        int n = s.size();
        int l = 0, r = n - 1;
        while (l < r && s[l] == s[r])
        {
            l++, r--;
        }
        if (l >= r)
            return true;
        return check(s, l + 1, r) || check(s, l, r - 1);
    }
};