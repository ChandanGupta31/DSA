#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

// Time Complexity = O(n3)
// Space Complexity = O(1)
void bruteCode(vector<vector<int>> &arr, int n, int m){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j]==0)
            {
                for (int k = 0; k < m; k++)
                {
                    if (arr[i][k]!=0)
                    {
                        arr[i][k]=-1;
                    }
                }
                for (int l = 0; l < n; l++)
                {
                    if (arr[l][j]!=0)
                    {
                        arr[l][j]=-1;
                    }
                }
            }
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j]==-1)
            {
                arr[i][j]=0;
            }
        }
    }
}



// Time Complexity = O(n2)
// Space Complexity = O(m+n)
void betterCode(vector<vector<int>> &arr, int n, int m){
    vector<int> row(n,0);
    vector<int> column(m,0);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j]==0)
            {
                row[i]=1;
                column[j]=1;
            }
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (row[i]==1 || column[j]==1)
            {
                arr[i][j]=0;
            }
        }
    }
}



// Time Complexity = O(n2)
// Space Complexity = O(1)
void optimalCode(vector<vector<int>> &arr, int n, int m){
    int col0 = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j]==0)
            {
                arr[i][0]=0;  // row
                if (j!=0)
                {
                    arr[0][j]=0;    // column
                }
                else
                {
                    col0 = 0;
                }
                
            }
        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (arr[i][0]==0 || arr[0][j]==0)
            {
                arr[i][j]=0;
            }
        }
    }
    
    if (arr[0][0]==0)
    {
        for (int i = 0; i < m; i++)
        {
            arr[0][i]=0;
        }
    }
    
    if (col0==0)
    {
        for (int i = 0; i < m; i++)
        {
            arr[i][0]=0;
        }
    }
}





// Q. Set the matrix zero. Given a binary matrix you have to find the zero and mark row and column values with zero
int main(){

    vector<vector<int>> arr = {{1,1,1,1},{1,0,0,1},{1,1,0,1},{1,1,1,1}};

    // bruteCode(arr, arr.size(), arr[0].size());
    // betterCode(arr, arr.size(), arr[0].size());
    optimalCode(arr, arr.size(), arr[0].size());

    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[0].size(); j++)
        {
            cout << arr[i][j] << '\t';
        }
        cout << endl;
    }
    
    return 0;
}