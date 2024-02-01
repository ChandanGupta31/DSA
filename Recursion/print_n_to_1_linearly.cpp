#include<iostream>
using namespace std;

// Q3. Print Linearly from N to 1;
void printFromNToOne(int n){
    if(n>0){
        cout << n << endl;
        printFromNToOne(--n);
    }
}

int main(){
    int n;
    cin >> n;
    printFromNToOne(n);
    return 0;
}