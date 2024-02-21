#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

// Time Complexity = O(n2)
// Space Complexity = O(1)
vector<int> bruteCode(vector<int> &arr, int n){
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (ans.size()==0 || ans[0]!=arr[i])
        {
            int count = 0;
            for (int j = 0; j < n; j++)
            {
                if (arr[j]==arr[i])
                {
                    count++;
                }
            }
            if (count>n/3)
            {
                ans.push_back(arr[i]);
            }   
        }
        if (ans.size()==2)
        {
            break;
        }
    }
    return ans;
}



// Time Complexity = O(n log n)
// Space Complexity = O(n)
vector<int> betterCode(vector<int> &arr, int n){
    vector<int> ans;
    int min_appear = n/3 + 1;

    map<int,int> mp;

    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
        if (mp[arr[i]]==3)
        {
            ans.push_back(arr[i]);
        }
    }
    return ans;
}



// Time Complexity = O()
// Space Complexity = O()
vector<int> optimalCode(vector<int> &arr, int n){
    vector<int> ans;
    int counter1 = 0, counter2 = 0;
    int element1 = INT16_MIN, element2 = INT16_MIN;
    for (int i = 0; i < arr.size(); i++)
    {
        if (counter1==0 && element2 != arr[i])
        {
            counter1 = 1;
            element1 = arr[i];
        }
        else if (counter2==0 && element1 != arr[i])
        {
            counter2 = 1;
            element2 = arr[i];
        }
        else if (arr[i]==element1)
        {
            counter1++;
        }
        else if (arr[i]==element2)
        {
            counter2++;
        }
        else
        {
            counter1--;
            counter2--;
        }
    }
    counter1=0;
    counter2=0;

    for (int i = 0; i < n; i++)
    {
        if (element1==arr[i])
        {
            counter1++;
        }
        if (element2==arr[i])
        {
            counter2++;
        }
    }
    
    int minreq = n/3 + 1;
    if (counter1>=minreq)
    {
        ans.push_back(element1);
    }
    if (counter2>=minreq)
    {
        ans.push_back(element2);
    }
    return ans;
}





// Q. Find the elements that appears more than n/3 times in array
int main(){

    vector<int> arr = {1,1,1,3,3,2,2,2};

    // vector<int> ans = bruteCode(arr, arr.size());
    // vector<int> ans = betterCode(arr, arr.size());
    vector<int> ans = optimalCode(arr, arr.size());
    
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << '\t';
    }
    cout << endl;
    
    return 0;
}