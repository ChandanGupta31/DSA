#include <iostream>
#include <vector>
using namespace std;

void mergeSort(vector<int> &arr, int low, int mid, int high)
{
    vector<int> v;
    int left = low;
    int right = mid+1;

    // if both right and left array has element
    while (left<=mid && right<=high)
    {
        if (arr[left]<=arr[right])
        {
            v.push_back(arr[left]);
            left++;
        }
        else
        {
            v.push_back(arr[right]);
            right++;
        }
        
        
    }

    // if only left array has element and right has exhausted
    while (left<=mid)
    {
        v.push_back(arr[left]);
        left++;
    }
    
    // if only right array has element and left has exhausted
    while (right<=high)
    {
        v.push_back(arr[right]);
        right++;
    }
    
    for (int i = low; i <= high; i++)
    {
        arr[i] = v[i-low];
    }
    
}

void merge(vector<int> &arr, int low, int high)
{
    if (low >= high)
        return;

    int mid = (low + high) / 2;
    merge(arr, low, mid);
    merge(arr, mid + 1, high);

    mergeSort(arr, low, mid, high);
}

int main()
{
    vector<int> arr = {5,4,7,8,9,6,3,2,1,4,5};

    merge(arr, 0, 10);

    // n = 11
    for (int i = 0; i < 11; i++)
    {
        cout << arr[i] << '\t';
    }
    
    return 0;
}