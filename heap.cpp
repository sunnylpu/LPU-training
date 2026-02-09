#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
class Compare
{
public:
    bool operator()(pii a, pii b)
    {
        return false;
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    priority_queue<int> pq;                              // max heap
    priority_queue<int, vector<int>, greater<int>> mnpq; // min heap
    priority_queue<pii, vector<pii>, Compare> custom_pq;

    pq.push(1);
    pq.pop();
    pq.top();
    pq.empty();
}
class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>> mnpq; // min heap
        for (auto x : nums)
        {
            mnpq.push(x);
        }
        while (mnpq.size() > k)
        {
            mnpq.pop();
        }
        return mnpq.top();
    }
};
class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>> mnpq; // min heap
        for (auto x : nums)
        {
            mnpq.push(x);
            if (mnpq.size() > k)
                mnpq.pop();
        }
        return mnpq.top();
    }
};
class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>> mnpq; // min heap
        for (auto x : nums)
        {
            if (mnpq.size() == k)
            {
                if (x < mnpq.top())
                    continue;
                mnpq.pop();
            }
            mnpq.push(x);
        }
        return mnpq.top();
    }
};