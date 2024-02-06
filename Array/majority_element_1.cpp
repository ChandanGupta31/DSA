#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// Time Complexity  = O(n2)
// Space Complexity = O(1)
int bruteCode(vector<int> &arr, int n){
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int  j = 0; j < n; j++)
        {
            if (arr[i]== arr[j])
            {
                count++;
            }
        }
        if (count>n/2)
        {
            return arr[i];
        }
    }
    return -1;
}


// Time Complexity = O(n log n)
// Space Complexity = O(n)
int betterCode(vector<int> &arr, int n){
    map<int, int> hash;
    
    for (int i = 0; i < n; i++)
    {
        hash[arr[i]]++;
    }
    
    for(auto it: hash){
        if (it.second > n/2)
        {
            return it.first;
        }
    }
    return -1;
}


// Time Complexity = O(n)
// Space Complexity = O(1)
// Moore's Voting Algorithm
int optimalCode(vector<int> arr, int n){
    int count = 0;
    int element = 0;
    for (int i = 0; i < n; i++)
    {
        if (count==0)
        {
            element=arr[i];
        }
        if (arr[i]==element)
        {
            count++;
        }
        else{
            count--;
        }
    }
    return element;
}



// Find the element that appears more than n/2 times
int main(){
    vector<int> arr = {2,2,3,3,1,2,2};

    cout << bruteCode(arr, arr.size()) << endl;
    cout << betterCode(arr, arr.size()) << endl;
    cout << optimalCode(arr, arr.size()) << endl;

    return 0;
}