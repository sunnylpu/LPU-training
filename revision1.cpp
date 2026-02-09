#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    greater<int> g;
    cout << g(10, 20) << endl; // first> second
    priority_queue<int,
                   vector<int>,
                   greater<int>>
        pq;
    less<int> l;
    cout << l(20, 30) << endl; // first< second
}
vector<int> merge_vectors(const vector<int> &left, const vector<int> &right, int &ans)
{
    int n1 = left.size();
    int n2 = right.size();
    vector<int> res(n1 + n2);

    int i = 0, j = 0, ptr = 0;

    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
        {
            res[ptr++] = left[i++];
        }
        else
        {
            res[ptr++] = right[j++];
            ans += (n1 - i);
        }
    }

    // Append remaining elements
    while (i < n1)
        res[ptr++] = left[i++];
    while (j < n2)
        res[ptr++] = right[j++];

    return res;
}

// 2. Updated merge_sort to work with vectors
vector<int> merge_sort(const vector<int> &arr, int &ans)
{
    int n = arr.size();

    // Base case: a vector of size 1 is already sorted
    if (n <= 1)
        return arr;

    int mid = n / 2;

    // Split the vector into two halves
    vector<int> left_half(arr.begin(), arr.begin() + mid);
    vector<int> right_half(arr.begin() + mid, arr.end());

    // Recursively sort both halves
    auto sorted_left = merge_sort(left_half, ans);
    auto sorted_right = merge_sort(right_half, ans);

    // Merge and return
    return merge_vectors(sorted_left, sorted_right, ans);
}

class Solution
{
    int ans = 0;

public:
    int inversionCount(vector<int> &arr)
    {
        // Code Here

        merge_sort(arr, ans);
        return ans;
    }
};
// k closest points to origin
#define pii pair<int, int>
class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        if (points.size() <= k)
            return points;
        sort(
            points.begin(),
            points.end(),
            [](vector<int> a, vector<int> b)
            {
                int dA = a[0] * a[0] + a[1] * a[1];
                int dB = b[0] * b[0] + b[1] * b[1];
                return dA <= dB;
            });
        vector<vector<int>> ans;
        for (int i = 0; i < k; i++)
            ans.push_back(points[i]);
        return ans;
    }
};