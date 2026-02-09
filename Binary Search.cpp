#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

// koko eating bananas
class Solution
{
public:
    bool helper(long long int k, vector<int> piles, long long int h)
    {
        long long int sm = 0;
        for (long long int x : piles)
        {
            sm += (x + k - 1) / k;
        }
        return sm <= h;
    }
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int n = piles.size();
        long long int lo = 1, hi = *max_element(piles.begin(), piles.end()) + 1;
        while (lo < hi)
        {
            long long int mid = lo + (hi - lo) / 2;
            if (helper(mid, piles, h))
                hi = mid;
            else
                lo = mid + 1;
        }
        return lo;
    }
};

// rotated sorted array
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int n = nums.size();
        int lo = 0, hi = n;
        while (lo < hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] < nums[0])
                hi = mid;
            else
                lo = mid + 1;
        }
        int pivot = lo;
        if (target >= nums[0])
            lo = 0, hi = pivot;
        else
            lo = pivot, hi = n;
        while (lo < hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] >= target)
                hi = mid;
            else
                lo = mid + 1;
        }
        if (lo >= n || nums[lo] != target)
            return -1;
        return lo;
    }
};

// valid perfect square
class Solution
{
public:
    bool isPerfectSquare(int num)
    {
        if (num == 0)
            return 0;
        long long int lo = 1, hi = num;
        hi++;
        while (lo < hi)
        {
            long long int mid = lo + (hi - lo) / 2;
            if (mid >= num / mid)
                hi = mid;
            else
                lo = mid + 1;
        }
        return lo * lo == num;
    }
};
// First Bad Version
// The API isBadVersion is defined for you.
bool isBadVersion(int version);

class Solution
{
public:
    int firstBadVersion(int n)
    {
        long long int lo = 1, hi = n;
        hi++;
        while (lo < hi)
        {
            long long int mid = lo + (hi - lo) / 2;
            if (isBadVersion(mid))
                hi = mid;
            else
                lo = mid + 1;
        }
        return lo;
    }
};

// kth missing value
class Solution
{
public:
    int missingcount(int mid, vector<int> arr)
    {
        return arr[mid] - mid - 1;
    }
    int findKthPositive(vector<int> &arr, int k)
    {
        if (k < arr[0])
            return k;
        int n = arr.size();
        int lo = 0, hi = n;
        while (lo < hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (missingcount(mid, arr) >= k)
                hi = mid;
            else
                lo = mid + 1;
        }
        int rem = k - missingcount(lo - 1, arr);
        return arr[lo - 1] + rem;
    }
};
// ship capacity
class Solution
{
public:
    bool helper(int capacity, vector<int> weights, int days)
    {
        int curr = 0, total_days = 1;
        for (auto x : weights)
        {
            if (x + curr > capacity)
            {
                total_days++;
                curr = 0;
            }
            curr += x;
        }
        return total_days <= days;
    }
    int shipWithinDays(vector<int> &weights, int days)
    {
        int n = weights.size();
        int lo = *max_element(weights.begin(), weights.end());
        int hi = accumulate(weights.begin(), weights.end(), 0) + 1;
        while (lo < hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (helper(mid, weights, days))
                hi = mid;
            else
                lo = mid + 1;
        }
        return lo;
    }
};
class Solution
{
public:
    int search(vector<int> &arr, int target)
    {
        int lo = 0, hi = arr.size();
        while (lo < hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (arr[mid] >= target)
                hi = mid;
            else
                lo = mid + 1;
        }
        return lo;
    }
    int search2(vector<int> &arr, int target)
    {
        int n = arr.size();
        int lo = 0, hi = arr.size();
        while (lo < hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (arr[mid] > target || (arr[mid] == target && (mid == n - 1 || arr[mid + 1] > arr[mid])))
                hi = mid;
            else
                lo = mid + 1;
        }
        return lo;
    }
    vector<int> searchRange(vector<int> &arr, int target)
    {
        int first = search(arr, target);
        if (first == arr.size() || arr[first] != target)
            return {-1, -1};
        int last = search2(arr, target);
        return {first, last};
    }
};

// flower bloom
// https://leetcode.com/submissions/detail/1906496361/
class Solution
{
public:
    bool helper(vector<int> &B, int day, int m, int k)
    {
        int curr = 0;
        int n = B.size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (B[i] > day)
            {
                // not bloomed
                curr = 0;
            }
            else
            {
                curr++;
            }
            if (curr == k)
            {
                ans++;
                curr -= k;
            }
        }
        return ans >= m;
    }
    int minDays(vector<int> &B, int m, int k)
    {
        long long int n = B.size();
        if (n / m < k)
            return -1;
        int lo = *min_element(B.begin(), B.end());
        int hi = *max_element(B.begin(), B.end()); // search space doesnt include hi+1
        while (lo < hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (helper(B, mid, m, k))
                hi = mid;
            else
                lo = mid + 1;
        }
        return lo;
    }
};
// split array largest sum
class Solution
{
public:
    int helper(vector<int> &nums, int capacity, int k)
    {
        int sum = 0;
        int cnt = 1;
        for (auto x : nums)
        {
            if (sum + x > capacity)
            {
                cnt++;
                sum = x;
            }
            else
                sum += x;
        }
        return cnt <= k;
    }
    int splitArray(vector<int> &nums, int k)
    {
        int n = nums.size();
        int lo = *max_element(nums.begin(), nums.end());
        int hi = accumulate(nums.begin(), nums.end(), 0) + 1;
        while (lo < hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (helper(nums, mid, k))
                hi = mid;
            else
                lo = mid + 1;
        }
        return lo;
    }
};
