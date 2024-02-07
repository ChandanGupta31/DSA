#include<iostream>
using namespace std;

// Q2. Find the frequency of each character of a string
int main(){

    string s = "chandankumarguptabgt";
    int arr[26] = {0};

    for (int i = 0; i < 20; i++)
    {
        arr[s[i]-97]++;
    }

    for (int i = 0; i < 26; i++)
    {
        cout << char(97+i) << " -> " << arr[i] << endl;
    }
    
    return 0;
    
}