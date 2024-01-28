#include<iostream>
using namespace std;

// Bubble Sort
int main(){
    int arr[] = {2,5,4,7,93,4,6,8,4,6,10,7,5,2,4,9};

    // n=16
    for (int i = 15; i >0; i--)
    {
        for (int j = 0; j < i; j++)
        {
           if(arr[j]>arr[j+1]){
            swap(arr[j], arr[j+1]);
           } 
        }
        
    }

    for (int i = 0; i < 16; i++)
    {
        cout << arr[i] << endl;
    }
    
    
    return 0;
}