#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//Q. Left rotate the array by k places

// Brute Code
// Time Complexity = O(n)
// Space Complexity = O(n+d), extra space = O(d)
void bruteCode(vector<int> &arr, int k, int n){

    vector<int> temp;

    for (int i = 0; i < k; i++)
    {
        temp.push_back(arr[i]);
    }
    

    for (int i = k; i < n; i++)
    {
        arr[i-k] = arr[i];
    }

    for (int i = n-k; i < n; i++)
    {
        arr[i] = temp[i-(n-k)];
    }
    
    
}


// Optimal Solution
// The approach is to reverse the array in the given manner
// 1. reverse(a, a+k), 2. reverse(a+k, a+n). 3. reverse(a, a+n);
// Time Complexity = O(2n) = O(n)
// Space Complexity = O(1)
void optimal(vector<int> &arr, int k, int n){
    reverse(arr.begin(), arr.begin()+k);    // inbuilt function
    reverse(arr.begin()+k, arr.end());
    reverse(arr.begin(), arr.end());
}

int main(){
    vector<int> arr = {4,5,7,9,6,8,2,3,1};
    int k;
    cout << "Enter the number of rotation\t";
    cin >> k;

    k = k%arr.size();   // Do this because on every complete rotation we get the same array

    // bruteCode(arr, k, arr.size());

    optimal(arr, k, arr.size());

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << '\t';
    }
    

    return 0;
}