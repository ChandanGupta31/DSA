#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

// Time Complexity = O(n2)
// Space Complexity = O(n)
vector<int> bruteCode(vector<int> &arr, int n){
    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        bool leader = true;
        for (int j = i+1; j < n; j++)
        {
            if (arr[i]<arr[j])
            {
                leader = false;
                break;
            }
        }
        if (leader)
        {
            ans.push_back(arr[i]);
        }
    }
    return ans;
}




// Time Complexity = O(n)
// Space Complexity = O(n)
vector<int> optimalCode(vector<int> &arr, int n){
    int mx = INT16_MIN;
    vector<int> ans;

    for (int i = n-1; i >=0; i--)
    {
        if (arr[i]>mx)
        {
            mx = arr[i];
            ans.push_back(arr[i]);
        }
    }

    return ans;
}





// Q. Leader In an array - Everything on the right should be smaller
int main(){

    vector<int> arr = {10,22,12,3,0,6};

    // vector<int> ans = bruteCode(arr, arr.size());
    vector<int> ans = optimalCode(arr, arr.size());

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << '\t';
    }
    cout << endl;
    

    return 0;
}