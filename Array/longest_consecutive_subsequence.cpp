#include<iostream>
#include<vector>
#include<map>
#include <unordered_set>
#include<algorithm>

using namespace std;

// Time Complexity = O(n3)
// Space Complexity = O(1)
int bruteCode(vector<int> &arr, int n){
    int longest = 1;
    for (int i = 0; i < n; i++)
    {
        int x = arr[i];
        int count = 1;
        bool flag = true;
        while (flag)
        {
            bool flag2 = true;
            for (int i = 0; i < n; i++)
            {
                if (arr[i]==x+1)    
                {
                    x++;
                    count++;
                    flag2 = false;
                    break;
                }
            }
            if (flag2)
            {
                longest = max(longest,count);
                break;
            }
        }
    }
    return longest;
}



// Time Complexity = O(n log n)
// Space Complexity = O(1)
int betterCode(vector<int> &arr, int n){
    sort(arr.begin(), arr.end());

    int longest = 1, count_current = 0, last_min = INT16_MIN;
    for (int i = 0; i < n; i++)
    {
        if (arr[i]-1==last_min)
        {
            count_current++;
            last_min = arr[i];
        }
        else if (arr[i]!=last_min)
        {
            count_current = 1;
            last_min = arr[i];
        }
        longest = max(longest, count_current);
    }
    return longest;
}



// Time Complexity = O(n)
// Space Complexity = O(n)
int optimalCode(vector<int> &arr, int n){
    unordered_set<int> s(arr.begin(), arr.end());

    int longest = 1;
    for (auto it: s)
    {
        if (s.find(it -1) == s.end())
        {
            int count = 1;
            int x = it;
            while (s.find(x+1) != s.end())
            {
                x++;
                count++;
            }
            longest  = max(longest, count);
        }
    }
    return longest;
}





// Q. Longest Subsequence in an array.
int main(){

    vector<int> arr = {102,4,100,1,101,3,2,1};

    cout << bruteCode(arr, arr.size()) << endl;
    cout << betterCode(arr, arr.size()) << endl;
    cout << optimalCode(arr, arr.size()) << endl;

    return 0;
}