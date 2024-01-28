#include<iostream>
using namespace std;

// Insertion Sort
int main(){

    int arr[] = {1,5,7,9,5,4,2,3,6,8,7,10,2,5,9,8,};

    // n = 16
    for (int i = 0; i < 16; i++)
    {
        int j=i;
        while (j>0 && arr[j-1]>arr[j])
        {
            swap(arr[j-1],arr[j]);
            j--;
        }
        
    }

    for (int i = 0; i < 16; i++)
    {
        cout << arr[i] << endl;
    }
    
    
    return 0;
}