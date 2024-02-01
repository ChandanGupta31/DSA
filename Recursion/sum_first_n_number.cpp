#include<iostream>
using namespace std;

// Q6. Print the sum of first N numbers
int sum(int n){
    if(n==0)    return 0;
    return n+sum(n-1);
}

int main(){
    int n;
    cin >> n;
    cout << sum(n) << endl;
    return 0;
}