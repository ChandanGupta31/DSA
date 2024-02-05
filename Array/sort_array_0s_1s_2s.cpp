#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Time Complexity = O(n log n)
// Space Complexity = O(n)
// sort the array using any sorting algorithm
void bruteCode(vector<int> &arr){
    sort(arr.begin(), arr.end());   // It uses merge sort algorithm
}

// Time Complexity = O(2n) = O(n)
// Space Complexity = O(1)
// Count the occurrence and overwrite it
void betterCode(vector<int> &arr, int n){
    int count0 = 0;
    int count1 = 0;
    int count2 = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i]==0)
        {
            count0++;
        }
        else if (arr[i]==1)
        {
            count1++;
        }
        else
        {
            count2++;
        }
    }

    for (int i = 0; i < count0; i++)
    {
        arr[i]=0;
    }
    for (int i = count0; i < count0+count1; i++)
    {
        arr[i]=1;
    }
    for (int i = count0+count1; i < count0+count1+count2; i++)
    {
        arr[i]=2;
    }
}


// Time Complexity = O(n)
// Space Complexity = O(1)
// Dutch National Flag Algorithm
void optimalCode(vector<int> &arr, int n){
    int low = 0;
    int mid = 0;
    int high = n-1;

    while (mid<=high)
    {
        if (arr[mid]==0)
        {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid]==1)
        {
            mid++;
        }
        else
        {
            swap(arr[mid],arr[high]);
            high--;
        }
    }
}

// Sort an array consist of 0s, 1s, 2s,
int main(){

    vector<int> arr = {0,1,2,0,1,2,1,2,0,0,0,1};

    // bruteCode(arr);
    // betterCode(arr, arr.size());
    optimalCode(arr, arr.size());

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << '\t';
    }
    

    return 0;
}