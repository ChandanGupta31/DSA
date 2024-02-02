#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

// Time Complexity = O(n log n)
// Space Complexity = O(1)
void bruteCode(vector<int> &arr1, vector<int> &arr2, vector<int> &arrU){
    set<int> s;

    for (int i = 0; i < arr1.size(); i++)
    {
        s.insert(arr1[i]);
    }

    for (int i = 0; i < arr2.size(); i++)
    {
        s.insert(arr2[i]);
    }
    
    int i=0; 
    for(auto it: s){
        arrU.push_back(it);
        i++;
    }
}


// Time Complexity = O(n)
// Space Complexity = O(1)
void optimalCode(vector<int> &arr1, vector<int> &arr2, vector<int> &arrU){
    int i = 0;
    int j = 0;
    
    while (i<arr1.size() && j<arr2.size())
    {
        if(arr1[i]<=arr2[j]){
            arrU.push_back(arr1[i]);
            i++;
        } 
        else{
            arrU.push_back(arr2[j]);
            j++;
        }
    }

    for (int k = i; k < arr1.size(); k++)
    {
        arrU.push_back(arr1[k]);
    }

    for (int k = j; k < arr2.size(); k++)
    {
        arrU.push_back(arr2[k]);
    }
    
}


// Q. Find the union of two sorted array
int main(){

    vector<int> arr1 = {1,1,2,3,4,5,8,9};
    vector<int> arr2 = {2,2,4,6,9};
    vector<int> arrU;

    // bruteCode(arr1, arr2, arrU);
    optimalCode(arr1, arr2, arrU);

    for (int  i = 0; i < arrU.size(); i++)
    {
        cout << arrU[i] << '\t';
    }
    
    return 0;
}