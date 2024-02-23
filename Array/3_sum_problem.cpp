#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>

using namespace std;

// Time Complexity = O(n3)
// Space Complexity = 2*O(no of triplet)
vector<vector<int>> bruteCode(vector<int> &arr, int n){
    set<vector<int>> ans;
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            for (int k = j+1; k < n; k++)
            {
                if (arr[i]+arr[j]+arr[k]==0)
                {
                    vector<int> temp = {arr[i], arr[j], arr[k]};
                    sort(temp.begin(), temp.end());
                    ans.insert(temp);
                }
                
            }
            
        }
        
    }
    vector<vector<int>> result(ans.begin(), ans.end());
    return result;
}



// Time Complexity = O(n2 log m)
// Space Complexity = O(n) + O(no of triplet)*2
vector<vector<int>> betterCode(vector<int> &arr, int n){
    set<vector<int>> st;
    for (int i = 0; i < n; i++)
    {
        set<int>hashSet;
        for (int j = i+1; j < n; j++)
        {
            int third = -(arr[i]+arr[j]);
            if (hashSet.find(third) != hashSet.end())
            {
                vector<int> temp = {arr[i], arr[j], third};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            hashSet.insert(arr[j]);
        }
        
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}



// Time Complexity = O(n2)
// Space Complexity = O(no of unique triplet)
vector<vector<int>> optimalCode(vector<int> &arr, int n){
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;

    for (int i = 0; i < n; i++)
    {
        if (i>0 && arr[i]==arr[i-1])    continue;
        int j = i+1;
        int k = n-1;

        while (j<k)
        {
            int sum = arr[i] + arr[j] + arr[k];
            if (sum<0)
            {
                j++;
            }
            else if (sum>0)
            {
                k--;
            }
            else
            {
                vector<int> temp = {arr[i], arr[j], arr[k]};
                ans.push_back(temp);
                j++;
                k--;
                while (j < k && arr[j]==arr[j-1])
                {
                    j++;
                }
                while (j < k && arr[k]==arr[k+1])
                {
                    k--;
                }
            }
            
        }
        
    }
    
    return ans;
}





// Q. 3 sum problem
int main(){

    vector<int> arr = {-1,0,1,2,-1,-4};

    // vector<vector<int>> ans = bruteCode(arr, arr.size());
    // vector<vector<int>> ans = betterCode(arr, arr.size());
    vector<vector<int>> ans = optimalCode(arr, arr.size());


    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << ans[i][j] << '\t';
        }
        cout << endl;
    }

    return 0;
}