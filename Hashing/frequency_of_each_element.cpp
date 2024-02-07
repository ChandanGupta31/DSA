#include<iostream>
using namespace std;

// Q1. Find the frequency of each element of an array
int main(){

    int arr[] = {1,5,7,9,0,2,3,6,5,4,7,8,9,5,2,1,3,6,5,4,7,9,9,2,5};
    int frequency[10] = {0};

    for (int i = 0; i < 25; i++)
    {
        frequency[arr[i]]++;
    }

    for (int i = 0; i < 10; i++)
    {
        cout << i <<" ->" << frequency[i] << endl;
    }
    

    return 0;
}