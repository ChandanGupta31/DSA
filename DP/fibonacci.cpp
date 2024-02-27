#include<iostream>
#include<vector>
using namespace std;

// Time Complexity = O(n)
// Space Complexity = O(n) + recursion stack space O(N)
int memoization(vector<int> &dp, int n){
    if (n <=1)  return n;
    if (dp[n]!=-1)  return dp[n];

    return dp[n] = memoization(dp, n-1) + memoization(dp, n-2);
}

// Time Complexity = O(n)
// Space Complexity = O(n)
int tabulation(vector<int> &dp, int n){
    for (int i = 2; i <= n; i++) dp[i] = dp[i-1] + dp[i-2];
    return dp[n];
}

// Time Complexity = O(n)
// Space Complexity = O(1)
int optimalSolution(int n){
    int pre1 = 1;
    int pre2 = 0;

    for (int i = 2; i <= n; i++)
    {
        int temp = pre1;
        pre1 +=pre2;
        pre2 = temp;
    }
    
    return pre1;
}

int main(){

    int n;
    cin >> n;
    vector<int> dp(n+1, -1);
    dp[0] = 0;  // for tabulation
    dp[1] = 1;  // for tabulation

    cout << memoization(dp, n) << endl;
    cout << tabulation(dp, n) << endl;
    cout << optimalSolution(n) << endl;


    return 0;
}