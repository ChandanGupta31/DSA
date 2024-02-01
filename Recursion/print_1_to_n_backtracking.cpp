#include<iostream>
using namespace std;

//Q4. Print Linearly from 1 to N but by Backtracking
void printLinearlyBacktracking(int n){
    if(n>0){
        printLinearlyBacktracking(--n);
    }
    cout << ++n << endl;
}

int main(){
    int n;
    cout << "enter the value of n";
    cin >> n;
    printLinearlyBacktracking(n);
    return 0;
}