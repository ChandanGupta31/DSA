#include<iostream>
using namespace std;

// Q1. Print Name 5 times using recursion
void printName(int n){
    if(n<6){
        cout<< "Chandan"<< endl;
        printName(++n);
    }
}

int main(){
    printName(1);
    return 0;
}