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

// k most frequent elements
#define pii pair<int, int>
class Compare
{
public:
    bool operator()(pii A, pii B)
    {
        return A.first >= B.first;
    }
};

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        map<int, int> mp;
        for (auto x : nums)
            mp[x]++;
        priority_queue<pii, vector<pii>, Compare> pq;
        for (auto [x, freq] : mp)
        {
            pq.push({freq, x});
            if (pq.size() > k)
                pq.pop();
        }
        vector<int> ans;
        while (!pq.empty())
        {
            auto [f, x] = pq.top();
            pq.pop();
            ans.push_back(x);
        }
        return ans;
    }
};

// k  closest points to origin
#define pii pair<int, int>
int square(int a)
{
    return a * a;
}
int dist(pii a)
{
    return square(a.first) + square(a.second);
}
class Compare
{
public:
    bool operator()(pii A, pii B)
    {
        return dist(A) <= dist(B);
    }
};
class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        priority_queue<pii> pq;
        for (int i = 0; i < points.size(); i++)
        {
            auto point = points[i];
            pq.push(
                {dist({point[0], point[1]}), i});
            if (pq.size() > k)
                pq.pop();
        }
        vector<vector<int>> ans;
        while (!pq.empty())
        {
            auto [d, i] = pq.top();
            ans.push_back(points[i]);
            pq.pop();
        }
        return ans;
    }
};