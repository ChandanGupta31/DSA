#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// Time Complexity = O(n2)
// Space Complexity = O(1)
int bruteCode(vector<int> &arr, int n){
    for (int i = 1; i <= n; i++)
    {
        bool flag = true;
        for (int j = 0; j < n; j++)
        {
            if (arr[j]==i)
            {
                flag = false;
                break;
            }
        }

        if (flag)
        {
            return i;
        }
        
    }

    return 0;
    
}


// Time Complexity = O(n)
// Space Complexity = O(n)
int betterCode(vector<int> &arr, int n){
    vector<int> hash(n+1,0);

    for (int i = 0; i < n-1; i++)
    {
        hash[arr[i]]++;
    }

    for (int i = 1; i < n+1; i++)
    {
        if (hash[i]==0)
        {
            return i;
        }
        
    }
    
    return 0;
}


// Two optimal Solution exist
// 1. Sum of element => By doing this we get the sum of all element and we took sum of first n element and taking difference will give answer
// Time Complexity = O(n)
// Space Complexity = O(1)
int optimalCode1(vector<int> &arr, int n){
    int total = (n*(n+1))/2;
    int arrTotal = 0;

    for (int i = 0; i < n-1; i++)
    {
        arrTotal+= arr[i];
    }
    
    return total-arrTotal;
}

// 2. Other is taking XOR of all element, we have n numbers and the array first we take the the xor of all number and then xor of all elements, this will lead to the duplication of element and we get our result.
// Time Complexity = O(n)
// Space Complexity = O(1)
int optimalCode2(vector<int> &arr, int n){
    int ans = 0;

    for (int i = 1; i <= n; i++)
    {
        ans^=i;
    }
    for (int i = 0; i < n-1; i++)
    {
        ans^=arr[i];
    }
    return ans;
}

// Find the missing number in an array
int main(){

    vector<int> arr = {1,4,6,7,8,5,3,9};

    cout << bruteCode(arr,arr.size()+1) << endl;
    cout << betterCode(arr,arr.size()+1) << endl;
    cout << optimalCode1(arr,arr.size()+1) << endl;
    cout << optimalCode2(arr,arr.size()+1) << endl;

    return 0;
}