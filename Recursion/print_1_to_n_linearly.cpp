#include<iostream>
using namespace std;

// Q2. Print Linearly from 1 ot N
void printLinearlyFromOne(int x,int n){
    if(x<=n){
        cout<< x << endl;
        printLinearlyFromOne(++x, n);
    }
}

int main(){
    int n;
    cin >> n;
    printLinearlyFromOne(1,n);
    return 0;
}