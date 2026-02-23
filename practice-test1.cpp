// weekly contest 320

#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
// 1
class Solution
{
public:
    int unequalTriplets(vector<int> &nums)
    {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n - 2; i++)
        {
            for (int j = i + 1; j < n - 1; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    if (
                        nums[i] != nums[j] &&
                        nums[j] != nums[k] &&
                        nums[k] != nums[i])
                        ans++;
                }
            }
        }
        return ans;
    }
};
// 2
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<int> in;
    vector<vector<int>> closestNodes(TreeNode *root, vector<int> &queries)
    {
        inorder(root);
        vector<vector<int>> res;
        for (int q : queries)
        {
            vector<int> ans;
            auto idx = upper_bound(in.begin(), in.end(), q);
            if (idx != in.begin())
            {
                idx--;
                ans.push_back(*idx);
            }
            else
                ans.push_back(-1);
            idx = lower_bound(in.begin(), in.end(), q);
            if (idx != in.end())
            {
                ans.push_back(*idx);
            }
            else
                ans.push_back(-1);
            res.push_back(ans);
        }
        return res;
    }

    void inorder(TreeNode *root)
    {
        if (!root)
            return;
        inorder(root->left);
        in.push_back(root->val);
        inorder(root->right);
    }
};
// 3
class Solution
{
public:
    long long int ans = 0;
    long long int dfs(int node, int par, int seats, vector<vector<int>> &graph)
    {
        long long int sm = 1;
        for (int nei : graph[node])
        {
            if (nei == par)
                continue;
            int curr = dfs(nei, node, seats, graph);
            ans += ceil(curr / (double)seats);
            sm += curr;
        }
        return sm;
    }
    long long minimumFuelCost(vector<vector<int>> &roads, int seats)
    {
        int n = roads.size() + 1;
        vector<vector<int>> graph(n, vector<int>());
        for (auto road : roads)
        {
            int u = road[0], v = road[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        dfs(0, -1, seats, graph);
        return ans;
    }
};

// 4
#define pii pair<int, int>
class Solution
{
public:
    int minL;
    int MOD = 1e9 + 7;
    vector<vector<int>> memo;
    bool isPrime(int x)
    {
        return x == 2 || x == 3 || x == 5 || x == 7;
    }
    int helper(int idx, vector<int> &arr, vector<bool> &prime, int rem)
    {
        int n = arr.size();
        if (rem == 0)
            return idx == n;
        if (idx == n)
            return 0;
        if (n - idx < minL)
            return 0;
        if (!isPrime(arr[idx]))
            return 0;
        if (memo[idx][rem] != -1)
            return memo[idx][rem];
        int ans = 0;
        for (int i = idx + minL - 1; i < n; i++)
        {
            if (!isPrime(arr[i]))
            {
                ans += helper(i + 1, arr, prime, rem - 1);
                ans %= MOD;
            }
        }
        memo[idx][rem] = ans;
        return ans;
    }
    int beautifulPartitions(string s, int k, int minLength)
    {
        minL = minLength;
        vector<int> arr;
        vector<bool> prime;
        int n = s.size();
        memo.resize(n + 1, vector<int>(k + 1, -1));
        for (auto x : s)
        {
            arr.push_back(x - '0');
            prime.push_back(isPrime(x - '0'));
        }

        return helper(0, arr, prime, k);
    }
};