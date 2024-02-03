#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// Find the maximum consecutive 1 appears
// Time Complexity = O(n)
// Space Complexity = O(1)
int main(){
    vector<int> arr = {1,1,0,0,1,1,1,1,0,0,0,1,1,1};
    int mx = 0;
    int count = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i]==1)
        {
            count++;
            mx = max(mx,count);
        }
        else
        {
            count=0;
        }
    }
    
    cout << mx << endl;
    return 0;
}