#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// Time Complexity = O(n2)
// Space Complexity = O(1)
// Q. Print the matrix in spiral manner
int main()
{

    vector<vector<int>> arr = {
        {1, 2, 3, 4, 5, 6},
        {20, 21, 22, 23, 24, 7},
        {19, 32, 33, 34, 25, 8},
        {18, 31, 36, 35, 26, 9},
        {17, 30, 29, 28, 27, 10},
        {16, 15, 14, 13, 12, 11}};

    int top = 0, left = 0, right = arr[0].size() - 1, bottom = arr.size() - 1;

    while (left <= right && top <= bottom)
    {
        for (int i = left; i <= right; i++)
        {
            cout << arr[left][i] << " ";
        }

        top++;

        for (int i = top; i <= bottom; i++)
        {
            cout << arr[i][right] << " ";
        }

        right--;

        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
            {
                cout << arr[bottom][i] << " ";
            }

            bottom--;
        }

        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                cout << arr[i][left] << " ";
            }

            left++;
        }
    }

    return 0;
}