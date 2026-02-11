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
    vector<int> maxSlidingWindow(vector<int> &arr, int k)
    {
        int n = arr.size();
        vector<int> ans;
        multiset<int> mst;
        for (int r = 0; r < n; r++)
        {
            mst.insert(arr[r]); // inclusion
            if (r >= k)
            {
                // exclusion
                int l = r - k;
                mst.erase(mst.find(arr[l])); // removes only 1 element
            }
            if (r >= k - 1)
            {
                // valid window
                auto it = mst.end();
                it--;
                ans.push_back(*it);
            }
        }
        return ans;
    }
};