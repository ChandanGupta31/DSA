#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

// Time Complexity = O(n2)
// Space Complexity = O(1)
int bruteCode(vector<int> &arr, int n, int k){
    int totalSubArray = 0;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum+=arr[j];
            if (sum==k)
            {
                totalSubArray++;
            }
        }
    }
    return totalSubArray;
}



// Time Complexity = O(n log n)
// Space Complexity = O(n)
int optimalCode(vector<int> &arr, int n, int k){
    int preSum = 0;
    int count = 0;
    map<int, int> mpp;

    mpp[0] = 1;

    for (int i = 0; i < n; i++)
    {
        preSum+=arr[i];
        int remove = preSum - k;
        count+=mpp[remove];
        mpp[preSum] +=1;
    }
    
    return count;
}





// Q. Number of Sub-array with sum k
int main(){

    vector<int> arr = {1,2,3,-3,1,1,1,4,2,-3};
    int k;
    cin >> k;

    cout << bruteCode(arr, arr.size(), k) << endl;
    cout << optimalCode(arr, arr.size(), k) << endl;

    return 0;
}