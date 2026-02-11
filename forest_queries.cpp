#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, q;
    cin >> n >> q;
    vector<vector<int>> garden(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < n; i++)
    {
        string row;
        cin >> row;
        for (int j = 0; j < n; j++)
            if (row[j] == '*')
                garden[i + 1][j + 1] = 1;
    }
    // horizontal prefix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            garden[i + 1][j + 1] += garden[i + 1][j];
    // vertical
    for (int j = 0; j < n; j++)
        for (int i = 0; i < n; i++)
            garden[i + 1][j + 1] += garden[i][j + 1];
    for (int i = 0; i < q; i++)
    {
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;
        int ans = garden[y2][x2];
        ans -= garden[y1 - 1][x2];
        ans -= garden[y2][x1 - 1];
        ans += garden[y1 - 1][x1 - 1];
        cout << ans << endl;
    }
}