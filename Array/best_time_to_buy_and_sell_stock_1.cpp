#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;


// Time Complexity = O(n)
// Space Complexity = O(1)
int solution(vector<int> &arr, int n){
    int mn = arr[0];
    int profit = 0;
    for (int i = 0; i < n; i++)
    {
        int cost = arr[i]-mn;
        profit = max(cost, profit);
        mn = min(mn, arr[i]);
    }
    return profit;
}

// Q. Best time to buy and sell stock to maximize the profit
int main(){

    vector<int> arr = {7,1,5,3,6,4};
    cout << solution(arr, arr.size()) << endl;
    return 0;
}