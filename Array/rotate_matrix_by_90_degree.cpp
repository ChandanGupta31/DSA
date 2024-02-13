#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

// Time Complexity = O(n2)
// Space Complexity = O(n2)
// pick each element and place it at its correct place in the new matrix.
vector<vector<int>> bruteCode(vector<vector<int>> &arr, int n){
    vector<vector<int>> mat(n, vector<int> (n, 0));     // declaration of size of vector of vector

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            mat[j][n-i-1] = arr[i][j];
        }
    }
    return mat;
}



// Time Complexity = O(n2)
// Space Complexity = O(n)
// taking the transpose of the matrix then reverse every row
vector<vector<int>> optimalCode(vector<vector<int>> &arr, int n){
    // taking transpose of a matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            swap(arr[i][j], arr[j][i]);
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        reverse(arr[i].begin(), arr[i].end());
    }
    
    return arr;
}





// Q. given a square matrix, your task is to rotate the matrix by 90 degree in clockwise direction
// or we can say image
int main(){

    vector<vector<int>> mat = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};

    // brute code
    // vector<vector<int>> ans = bruteCode(mat, mat.size());
    
    // optimal code
    vector<vector<int>> ans = optimalCode(mat, mat.size());

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans.size(); j++)
        {
            cout << ans[i][j] << '\t';
        }
        cout << endl;
    }
    return 0;
}