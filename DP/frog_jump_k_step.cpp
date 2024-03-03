#include<iostream>
#include<vector>
using namespace std;






int solution(vector<int> &arr, vector<int> &dp, int n, int k){
    
    for (int i = 1; i < n; i++)
    {
        int pathValue = INT16_MAX;
        for (int j = 1; j <= k; j++)
        {
            if (i-j>=0)
            {
                int x = abs(arr[i]-arr[i-j]) + dp[i-j];
                pathValue = min(pathValue, x);
            }
            else
            {
                break;
            }
        }
        dp[i] = pathValue;
    }

    return dp[n-1];
}


// Frog jump with k step at a time
// Using tabulation method
int main(){

    vector<int> arr = {10,20,30,100,40,60,50,70,20};
    int k;
    cin >> k;
    vector<int> dp(arr.size()+1, 0);

    cout << solution(arr, dp, arr.size(), k) << endl;
    
    return 0;
}