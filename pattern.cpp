#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    // // 1. print columns

    // int n = 5;
    // for (int r = 0; r < n; r++)
    // {
    //     for (int c = 0; c < n; c++)
    //     {
    //         cout << c << "";
    //     }
    //     cout << endl;
    // }

    // // 2. print hollow rectangle

    // int rows = 5, cols = 10;
    // for (int r = 0; r < rows; r++)
    // {
    //     for (int c = 0; c < cols; c++)
    //     {
    //         // boundry check
    //         if (r == 0 || r == rows - 1 || c == 0 || c == cols - 1)
    //             cout << "*";
    //         else
    //             cout << " ";
    //     }
    //     cout << endl;
    // }
    // // 3. print right angled triangle

    // n = 10;
    // for (int r = 0; r < n; r++)
    // {
    //     for (int c = 0; c < n; c++)
    //     {
    //         if (c > r)
    //         {
    //             cout << "#";
    //         }
    //         else if (c == 0 || r == n - 1 || r == c)
    //             cout << "*";
    //         else
    //             cout << " ";
    //     }
    //     cout << endl;
    // }

    // 4. print manhattan distance from origin
    // n = 5;
    // for (int r = 0; r < n; r++)
    // {
    //     for (int c = 0; c < n; c++)
    //     {
    //         cout << r + c << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    // // 5. print manhattan distance from a random point
    // n = 5;
    // int x = 2, y = 3;
    // for (int r = 0; r < n; r++)
    // {
    //     for (int c = 0; c < n; c++)
    //     {
    //         cout << abs(r - x) + abs(c - y) << " ";
    //     }
    //     cout << endl;
    // }

    // 6. print a circle

    // int r = 20;
    // for (int i = -r; i <= r; i++)
    // {
    //     for (int j = -r; j <= r; j++)
    //     {
    //         if (i * i + j * j <= r * r)
    //             cout << "* ";
    //         else
    //             cout << "  ";
    //     }
    //     cout << endl;
    // }

    // 7. print a spiral (leetcode)
    class Solution
    {
    public:
        vector<int> spirallyTraverse(vector<vector<int>> &mat)
        {
            int n = mat.size();
            int m = mat[0].size();
            vector<int> ans;
            // code here
            int lbound = 0, rbound = m - 1, tbound = 0, bbound = n - 1;
            while (lbound <= rbound && tbound <= bbound)
            {
                int ptr = lbound;
                while (ptr <= rbound)
                {
                    ans.push_back(mat[tbound][ptr]);
                    ptr++;
                }
                tbound++;
                ptr = tbound;
                while (ptr <= bbound)
                {
                    ans.push_back(mat[ptr][rbound]);
                    ptr++;
                }
                rbound--;
                ptr = rbound;
                while (ptr >= lbound && tbound <= bbound)
                {
                    ans.push_back(mat[bbound][ptr]);
                    ptr--;
                }
                bbound--;
                ptr = bbound;
                while (ptr >= tbound && lbound <= rbound)
                {
                    ans.push_back(mat[ptr][lbound]);
                    ptr--;
                }
                lbound++;
            }
            return ans;
        }
    };
    // 8. print pascals triangle
    //     1
    //    1 1
    //   1 2 1
    //  1 3 3 1
    // 1 4 6 4 1
    // 1
    // 1 1
    // 1 2 1
    // 1 3 3 1
    // 1 4 6 4 1
    // n = 4;
    // int pascals[n + 1][n + 1];
    // for (int i = 0; i <= n; i++)
    // {
    //     for (int j = 0; j < n - i; j++)
    //         cout << " ";
    //     for (int j = 0; j <= i; j++)
    //     {
    //         if (j == 0 || j == i)
    //         {
    //             pascals[i][j] = 1;
    //             cout << pascals[i][j] << " ";
    //             continue;
    //         }
    //         pascals[i][j] = pascals[i - 1][j] + pascals[i - 1][j - 1];

    //         cout << pascals[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // 9. print xor pyramid
    //    4
    //   2 6
    //  3 1 7
    // 1 2 3 4
    // 4
    // 2 6
    // 3 1 7
    // 1 2 3 4
    // n = 4;
    // int arr[n][n];
    // arr[0][0] = 1;
    // arr[0][1] = 2;
    // arr[0][2] = 3;
    // arr[0][3] = 4;

    // for (int i = 1; i < n; i++)
    // {
    //     for (int j = 0; j <= n - i - 1; j++)
    //     {
    //         arr[i][j] = arr[i - 1][j] ^ arr[i - 1][j + 1];
    //     }
    // }

    // for (int i = n - 1; i >= 0; i--)
    // {
    //     for (int k = 0; k <= i; k++)
    //         cout << " ";
    //     for (int j = 0; j <= n - i - 1; j++)
    //         cout << arr[i][j] << " ";
    //     cout << endl;
    // }
}