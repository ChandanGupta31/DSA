#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

// Time Complexity = O(n2)
// Space Complexity = O(1)
int bruteCode(vector<int> &arr, int n){
    int mx = INT16_MIN;
    for (int i = 0; i < n; i++)
    {
        int total = 0;
        for (int j = i; j < n; j++)
        {
            total+=arr[j];
            mx = max(total, mx);
        }
    }
    return mx;
}

// Time Complexity = O(n)
// Space Complexity = O(1)
// Kadane's Algorithm
int optimalCode(vector<int> &arr, int n){
    int mx = INT16_MIN;
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum+=arr[i];
        mx = max(mx,sum);
        if (sum<0)
        {
            sum=0;
        }
    }
    return mx;
}

// Q. Find Maximum Sub-array Sum containing both positive and negative integers
int main(){

    vector<int> arr = {-2,-3,4,-1,-2,1,5,-3};

    cout << bruteCode(arr, arr.size()) << endl;
    cout << optimalCode(arr, arr.size()) << endl;

    return 0;
}