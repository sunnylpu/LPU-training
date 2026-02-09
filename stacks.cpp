#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
// Sum of Subarray Minimums
class Solution
{
public:
    int sumSubarrayMins(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> NSE(n, n), PSE(n, -1);
        stack<int> ns, ps;
        for (int i = 0; i < n; i++)
        {
            while (!ps.empty() && arr[ps.top()] > arr[i])
                ps.pop();
            if (!ps.empty())
                PSE[i] = ps.top();
            ps.push(i);
        }
        for (int i = n - 1; i >= 0; i--)
        {
            while (!ns.empty() && arr[ns.top()] >= arr[i])
                ns.pop();
            if (!ns.empty())
                NSE[i] = ns.top();
            ns.push(i);
        }
        long long int ans = 0;
        int MOD = 1000000007;
        for (int i = 0; i < n; i++)
        {
            long long int temp = arr[i];
            temp = (temp * (NSE[i] - i)) % MOD;
            temp = (temp * (i - PSE[i])) % MOD;
            ans = (ans + temp) % (MOD);
        }
        return ans;
    }
};
// Trapping Rain Water

class Solution
{
public:
    int trap(vector<int> &H)
    {
        int n = H.size();
        stack<int> s;
        int ans = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            while (!s.empty() && H[s.top()] <= H[i])
            {
                int mid = H[s.top()];
                s.pop();
                if (!s.empty())
                {
                    int left = i;
                    int right = s.top();
                    ans += (min(H[left], H[right]) - mid) * (right - left - 1);
                }
            }
            s.push(i);
        }
        return ans;
    }
};
// Using a Robot to Print the Lexicographically Smallest String
class Solution
{
public:
    string robotWithString(string s)
    {
        stack<int> t, st;
        string ans = "";
        int n = s.size();
        vector<int> suffmin(n);
        char mn = 'z';
        int curr_idx = n - 1;
        for (int i = n - 1; i >= 0; i--)
        {
            if (mn >= s[i])
            {
                mn = s[i];
                curr_idx = i;
            }
            suffmin[i] = curr_idx;
            st.push(i);
        }
        int idx = 0;
        while (!st.empty())
        {
            if (!t.empty() && s[t.top()] <= s[suffmin[idx]])
            {
                ans += s[t.top()];
                t.pop();
                continue;
            }
            while (!st.empty() && st.top() != suffmin[idx])
            {
                t.push(st.top());
                st.pop();
                idx++;
            }
            ans += s[suffmin[idx]];
            st.pop();
            idx++;
        }
        while (!t.empty())
        {
            ans += s[t.top()];
            t.pop();
        }
        return ans;
    }
};
// Largest Rectangle in Histogram
class Solution
{
public:
    int largestRectangleArea(vector<int> &H)
    {
        int n = H.size();
        vector<int> nse(n, -1), pse(n, -1);
        stack<int> sn, sp;
        for (int i = n - 1; i >= 0; i--)
        {
            while (!sn.empty() && H[sn.top()] >= H[i])
                sn.pop();
            nse[i] = sn.empty() ? n : sn.top();
            sn.push(i);
        }
        for (int i = 0; i < n; i++)
        {
            while (!sp.empty() && H[sp.top()] >= H[i])
                sp.pop();
            pse[i] = sp.empty() ? -1 : sp.top();
            sp.push(i);
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans = max(ans, H[i] * (nse[i] - pse[i] - 1));
        }
        return ans;
    }
};
// Longest valid parentheses
class Solution
{
public:
    int longestValidParentheses(string s)
    {
        int n = s.size();
        stack<int> stk;
        for (int i = 0; i < n; i++)
        {
            if (!stk.empty() && s[i] == ')' && s[stk.top()] == '(')
            {
                stk.pop();
                continue;
            }
            stk.push(i);
        }
        int ans = 0;
        int curr = n;
        while (!stk.empty())
        {
            int currLen = curr - stk.top() - 1;
            curr = stk.top();
            stk.pop();
            if (ans < currLen)
            {
                ans = currLen;
            }
        }
        if (curr > ans)
            ans = curr;
        return ans;
    }
};

// Valid Parentheses
class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> stk;
        map<char, char> mp;
        mp['}'] = '{';
        mp[')'] = '(';
        mp[']'] = '[';
        for (auto x : s)
        {
            if (mp[x]) // is this closing bracket
            {
                if (stk.empty())
                    return false;
                if (stk.top() != mp[x])
                    return false; // corresponding opening brakcet
                stk.pop();
                continue;
            }
            stk.push(x);
        }
        return stk.empty();
    }
};