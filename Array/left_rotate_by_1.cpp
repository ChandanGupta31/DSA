#include<iostream>
#include<vector>

using namespace std;

// Time Complexity = O(n)
// Space Complexity = O(1), but to solve the problem it internally uses O(n)

int main(){
    vector<int> v = {2,5,7,9,3,1,2,4,6,8};
    int temp = v[0];

    for (int i = 1; i < v.size(); i++)
    {
        v[i-1] = v[i];
    }

    v[v.size()-1] = temp;

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << "\t";
    }
    
    

    return 0;
}