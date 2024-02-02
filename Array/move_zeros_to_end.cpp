#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// Time Complexity = O(2n) -> O(n)
// Space Complexity  = O(n)
void bruteCode(vector<int> &arr, int n){
    vector<int> temp;
    for (int i = 0; i < n; i++)
    {
        if (arr[i]!=0)
        {
            temp.push_back(arr[i]);
        }
        
    }
    for (int  i = 0; i < temp.size(); i++)
    {
        arr[i] = temp[i];
    }

    for (int i = temp.size(); i < n; i++)
    {
        arr[i] = 0;
    }
    
}

// Time Complexity = O(n)
// Space Complexity = O(1)
void optimalCode(vector<int> &arr, int n){
    int j = -1;
    for (int i = 0; i < n; i++)
    {
        if(arr[i]==0){
            j = i;
            break;
        }
    }

    if (j==-1)
    {
        return;     // This is because array does not contain any 0
    }

    for (int i = j+1; i < n; i++)
    {
        if (arr[i]!=0)
        {
            swap(arr[i], arr[j]);
            j++;
        }
        
    }
    
    
    
}


// Q. Move all the zeros to the end of the array
int main(){

    vector<int> arr = {4,2,8,0,3,4,0,0,1,7,9,3,0,1,3,5};
    
    // bruteCode(arr, arr.size());
    optimalCode(arr, arr.size());

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << '\t';
    }
    
    return 0;
}