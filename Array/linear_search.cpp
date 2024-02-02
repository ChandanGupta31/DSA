#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


// Time Complexity = O(n)
// Space Complexity = O(1)
int linearSearch(vector<int> &arr, int n, int k){
    for (int i = 0; i < n; i++)
    {
        if (arr[i]==k)
        {
            return i;
        }
        
    }
    
}

// Q. Linear Search
int main(){

    vector<int> arr = {1,6,7,6,1,47,9,2,5,9,7,2,3,6};

    int k;
    cin >> k;
    cout << linearSearch(arr, arr.size(), k) << endl;

    return 0;
}