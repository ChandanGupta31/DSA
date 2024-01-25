#include<iostream>
using namespace std;

// Q1. Print Name 5 times using recursion
// void printName(int n){
//     if(n<6){
//         cout<< "Chandan"<< endl;
//         printName(++n);
//     }
// }

// int main(){
//     printName(1);
//     return 0;
// }





// Q2. Print Linearly from 1 ot N
// void printLinearlyFromOne(int x,int n){
//     if(x<=n){
//         cout<< x << endl;
//         printLinearlyFromOne(++x, n);
//     }
// }

// int main(){
//     int n;
//     cin >> n;
//     printLinearlyFromOne(1,n);
//     return 0;
// }





// Q3. Print Linearly from N to 1;
// void printFromNToOne(int n){
//     if(n>0){
//         cout << n << endl;
//         printFromNToOne(--n);
//     }
// }

// int main(){
//     int n;
//     cin >> n;
//     printFromNToOne(n);
//     return 0;
// }





// Q4. Print Linearly from 1 to N but by Backtracking
// void printLinearlyBacktracking(int n){
//     if(n>0){
//         printLinearlyBacktracking(--n);
//     }
//     cout << ++n << endl;
// }

// int main(){
//     int n;
//     cout << "enter the value of n";
//     cin >> n;
//     printLinearlyBacktracking(n);
//     return 0;
// }





//Q5. Print Linearly from N to 1 using backtracking
// void printReverseBacktracking(int x, int n){
//     if(x<n){
//         printReverseBacktracking(++x, n);
//         x--;
//     }
//     cout << x << endl;
// }

// int main(){
//     int n;
//     cin >> n;
//     printReverseBacktracking(1, n);
//     return 0;
// }