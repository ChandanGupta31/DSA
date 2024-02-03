#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// Time Complexity = O(n2)
// Space Complexity = O(1)
// Iterating through each element and count their appearance
int bruteCode(vector<int> &arr, int n){
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[i]==arr[j])
            {
                count++;
            }
        }
        if (count==1)
        {
            return arr[i];
        }
    }
    return 0;
}


// Time Complexity = O(n)
// Space Complexity = O(n/2) = O(n)
// Checking the frequency of each element, if the data is large then we use map
int betterCode(vector<int> &arr, int n){
    vector<int> temp((n/2)+2, 0);

    for (int i = 0; i < n; i++)
    {
        temp[arr[i]]++;
    }

    for (int i = 1; i <= temp.size(); i++)
    {
        if (temp[i]==1)
        {
            return i;
        }
        
    }
    return 0;
}

// Time Complexity = O(n)
// Space Complexity = O(1)
// Taking XOR of all the element, removes duplicates
int optimalCode(vector<int> &arr, int n){
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans^=arr[i];
    }
    return ans;
}


// Q. Find the number that appear once in the array while the other appears twice in the array
int main(){

    vector<int> arr = {2,4,5,6,3,8,7,1,3,2,1,4,5,6,9,8,7};

    cout << bruteCode(arr, arr.size()) << endl;
    cout << betterCode(arr, arr.size()) << endl;
    cout << optimalCode(arr, arr.size()) << endl;

    return 0;
}