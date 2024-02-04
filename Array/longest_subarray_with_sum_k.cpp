#include <iostream>
#include <vector>
#include<map>
#include <algorithm>

using namespace std;

// Time Complexity = O(n2)
// Space Complexity = O(1)
// Generate all the sub-array and check them
int bruteCode(vector<int> &arr, int n, int k)
{
    int maxLength = 0;
    for (int i = 0; i < n; i++)
    {
        int total = 0;
        for (int j = i; j < n; j++)
        {
            total += arr[j];
            if (total == k)
            {
                maxLength = max(maxLength, j - i + 1);
                break;
            }
        }
    }
    return maxLength;
}

// Time Complexity = O(n log n)
// Space Complexity = O(n)
// This is better solution for positive integers only but best solution for positive and negative integer
int betterCode(vector<int> &arr, int n, int k)
{
    map<long long, int> preSum;
    long  long sum = 0;
    int length = 0;

    for (int i = 0; i < n; i++)
    {
        sum +=arr[i];
        if (sum == k)   
        {
            length = max(length, i+1);
        }
        long long rem = sum-k;
        if (preSum.find(rem) != preSum.end())
        {
            int len = i-preSum[rem];
            length = max(length,len);
        }
        if (preSum.find(rem) == preSum.end())
        {
            preSum[sum]= i;
        }
    }
    return length;
}


// Time Complexity = O(2n) = O(n)
// Space Complexity = O(1)
// Using two pointer approach
int optimalCode(vector<int> &arr, int n, int k){
    int left = 0, right = 0;
    long long sum = 0;
    int length = 0;
    while (right<n)
    {
        while (left<=right && sum>k)
        {
            sum-=arr[left];
            left++;
        }
        if (sum==k)
        {
            length = max(length, right - left +1);
        }
        right++;
        if (right<=n)
        {
            sum+=arr[right];
        }
    }
    return length;
}

// Q. Find the longest sub-array(contigious) that sum is equal to k
int main()
{

    vector<int> arr = {1, 2, 3, 1, 1, 1, 1, 4, 2, 3};
    int k;
    cin >> k;

    cout << bruteCode(arr, arr.size(), k) << endl;
    cout << betterCode(arr, arr.size(), k) << endl;
    cout << optimalCode(arr, arr.size(), k) << endl;

    return 0;
}