#include<iostream>
using namespace std;

//Q5. Print Linearly from N to 1 using backtracking
void printReverseBacktracking(int x, int n){
    if(x<n){
        printReverseBacktracking(++x, n);
        x--;
    }
    cout << x << endl;
}

int main(){
    int n;
    cin >> n;
    printReverseBacktracking(1, n);
    return 0;
}