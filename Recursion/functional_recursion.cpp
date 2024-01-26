#include<iostream>
using namespace std;

// Q1. Reverse the Array
// void reverse(int l, int r, int arr[]){
//     if(l<r){
//         swap(arr[l], arr[r]);
//         reverse(l+1, r-1, arr);
//     }
// }

// int main(){
//     int arr[6] = {1,5,7,3,9,4};
//     reverse(0,5,arr);
//     for (int i = 0; i < 6; i++)
//     {
//         cout << arr[i] << endl;
//     }
//     return 0;
// }





// Q2. Check the given String is Palindrome
// bool palindrome(int l, string s, int r){
//     if(l>=r)    return true;
//     if(s[l]!= s[r]) return false;
//     return palindrome(l+1, s, r-1);
// }

// int main(){
//     string s = "Chandan";
//     cout << palindrome(0,s,4) << endl;
//     return 0;
// }