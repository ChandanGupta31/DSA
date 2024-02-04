#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

// Time Complexity = O(n2)
// Space Complexity = O(1)
int bruteCode(vector<int> &arr, int n, int target){
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (arr[i]+arr[j]==target)
            {
                return 1;
            }
        }
    }
    return 0;
}

// Time Complexity = O(n log n)
// Space Complexity = O(n)
int betterCode(vector<int> &arr, int n, int target){
    map<int,int> mp;
    for (int i = 0; i < n; i++)
    {
        int a = arr[i];
        int b = target - a;
        if (mp.find(b)!=mp.end())
        {
            return 1;
        }
        mp[a] = i;
    }
    return 0;
}

// Time Complexity = O(n log n)
// Space Complexity = O(1)
int optimalCode(vector<int> &arr, int n, int target){
    sort(arr.begin(), arr.end());
    int left = 0, right = n-1;
    while (left<right)
    {
        if(arr[left]+arr[right]==target){
            return 1;
        }
        else if (arr[left]+arr[right] < target)
        {
            left++;
        }
        else
        {
            right--;
        }
    }
    return 0; 
}


// Q1. Given an array and a target value. target is to find is there any two value in the array whose sum is equal to target
// Q2. Given an array and a target value. it is sure the target is met when we add two element . find those element index.
int main(){
    vector<int> arr = {2,6,5,8,11};
    int target;
    cin >> target;

    cout << bruteCode(arr, arr.size(), target) << endl;
    cout << betterCode(arr, arr.size(), target) << endl;
    cout << optimalCode(arr, arr.size(), target) << endl;

    return 0;
}