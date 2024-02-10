#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

// Time Complexity = O(n! * n)
// Space Complexity = O()
// Generate all the permutation in sorted order and then linear search to find it. To generate permutation use recursion.
void bruteCode(vector<int> &arr, int n){
    // Since the time complexity is quiet high therefore we just tell the approach not to write the code for it.
}



// Time Complexity = O()
// Space Complexity = O()
// for better solution in c++ only there is a function in stl
void betterCode(vector<int> &arr, int n){
    next_permutation(arr.begin(), arr.end());    
}



// Time Complexity = O(3n) = O(n)
// Space Complexity = O(1)
// the algorithm is best on matching the longer prefix
void optimalCode(vector<int> &arr, int n){
    int index = -1;

    for (int i = n-2; i >=0; i--)
    {
        if (arr[i]<arr[i+1])    
        {
            index = i;
            break;
        }
    }

    if (index==-1)
    {
        reverse(arr.begin()+index+1, arr.end());
        return;
    }
    
    
    for (int i = n-1; i >= index; i--)
    {
        if (arr[i] > arr[index])
        {
            swap(arr[i], arr[index]);
            break;
        }
    }

    reverse(arr.begin()+index+1, arr.end());
}





// Q. Next Permutation
int main(){

    vector<int> arr = {2,1,5,4,3,0,0};

    // betterCode(arr, arr.size());
    optimalCode(arr, arr.size());

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << '\t';
    }
    cout << endl;
    
    return 0;
}