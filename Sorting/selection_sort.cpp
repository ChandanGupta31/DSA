#include <iostream>
using namespace std;

// Selection Sort
int main()
{
    int arr[] = {5, 7, 9, 2, 4, 6, 2, 8, 8, 7, 1};

    // n = 11
    for (int i = 0; i < 10; i++)
    {
        int min_index = i;
        for (int j = i; j < 11; j++)
        {
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }
        swap(arr[i], arr[min_index]);
    }

    for (int i = 0; i < 11; i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}