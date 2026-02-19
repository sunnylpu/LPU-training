#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
// redundant connection
class Solution
{
public:
    vector<int> parent;
    void _union(int a, int b)
    {
        int pa = find(a);
        int pb = find(b);
        if (pa == pb)
            return;
        parent[pa] = pb;
    }
    int find(int a)
    {
        if (parent[a] == a)
            return a;
        int pa = find(parent[a]);
        parent[a] = pa; //  path compression
        return pa;
    }
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        int n = edges.size();
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
        for (auto edge : edges)
        {
            int u = edge[0], v = edge[1];
            if (find(u) == find(v))
                return {u, v};
            _union(u, v);
        }
        return {};
    }
};

// path exists
class Solution
{
public:
    vector<int> parent;
    void _union(int a, int b)
    {
        int pa = find(a);
        int pb = find(b);
        if (pa == pb)
            return;
        parent[pa] = pb;
    }
    int find(int a)
    {
        if (parent[a] == -1)
            return a;
        int pa = find(parent[a]);
        parent[a] = pa; // path compression
        return pa;
    }
    bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
    {
        parent.resize(n, -1);
        for (auto edge : edges)
        {
            int u = edge[0], v = edge[1];
            _union(u, v);
        }
        return find(source) == find(destination);
    }
};

// Count islands
#define pii pair<int, int>
class Solution
{
public:
    map<pii, pii> parent;
    bool _union(pii A, pii B)
    {
        pii pA = find(A);
        pii pB = find(B);
        if (pA == pB)
            return false; // cant union, same island;
        parent[pA] = pB;
        return true;
    }
    pii find(pii A)
    {
        if (parent[A] == A)
            return A;
        parent[A] = find(parent[A]);
        return parent[A];
    }
    int numIslands(vector<vector<char>> &grid)
    {
        int R = grid.size(), C = grid[0].size();
        for (int r = 0; r < R; r++)
        {
            for (int c = 0; c < C; c++)
            {
                parent[make_pair(r, c)] = make_pair(r, c);
            }
        }
        for (int r = 0; r < R; r++)
        {
            for (int c = 0; c < C; c++)
            {
                // combine
                if (grid[r][c] == '0')
                    continue;
                if (r + 1 < R && grid[r + 1][c] == '1')
                    _union(make_pair(r, c), make_pair(r + 1, c));
                if (r > 0 && grid[r - 1][c] == '1')
                    _union(make_pair(r, c), make_pair(r - 1, c));
                if (c + 1 < C && grid[r][c + 1] == '1')
                    _union(make_pair(r, c), make_pair(r, c + 1));
                if (c > 0 && grid[r][c - 1] == '1')
                    _union(make_pair(r, c), make_pair(r, c - 1));
            }
        }
        int cnt = 0;
        // find number of leaders
        for (int r = 0; r < R; r++)
        {
            for (int c = 0; c < C; c++)
            {
                if (grid[r][c] == '1' && find(make_pair(r, c)) == make_pair(r, c))
                    cnt++;
            }
        }
        return cnt;
    }
};