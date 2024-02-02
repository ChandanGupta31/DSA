#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// Time Complexity = O(n2)
// Space Complexity = O(n) 
void bruteCode(vector<int> &arr1, vector<int> &arr2, vector<int> &intersection){
    vector<int> visited(arr2.size(), 0);
    for (int i = 0; i < arr1.size(); i++)
    {
        for (int j = 0; j < arr2.size(); j++)
        {
            if(arr1[i]==arr2[j] && visited[j]==0){
                intersection.push_back(arr1[i]);
                visited[j] = 1;
                break;
            }
            if(arr1[i] < arr2[j]){
                break;
            }
        }
        
    }
    
}

// Time Complexity = O(n1+n2)
// Space Complexity = O(1)
void optimalCode(vector<int> &arr1, vector<int> &arr2, vector<int> &intersection){
    int i = 0;
    int j = 0;

    while (i<arr1.size() && j<arr2.size())
    {
        if(arr1[i]==arr2[j]){
            intersection.push_back(arr1[i]);
            i++;
            j++;
        }

        else if (arr1[i]<arr2[j])
        {
            i++;
        }
        else
        {
            j++;
        }
        
        
    }
    
}

// Q. Intersection of Two Sorted Array
int main(){

    vector<int> arr1 = {1,3,3,4,5,6,6,6,7,8,8};
    vector<int> arr2 = {1,2,3,4,5,6,6,7,7,8};

    vector<int> intersection;

    // bruteCode(arr1, arr2, intersection);
    optimalCode(arr1, arr2, intersection);

    for (int i = 0; i < intersection.size(); i++)
    {
        cout << intersection[i] << '\t';
    }
    

    return 0;
}