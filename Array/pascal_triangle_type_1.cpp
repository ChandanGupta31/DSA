#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

// Q. Given N and R find the element at that position in pascal triangle
// Time Complexity = O(r)
// Space Complexity = O(1)
long long solution1(int n, int r){
    long long result = 1;
    r = min(r, n-r);
    for (int i = 0; i < r; i++)
    {
        result*=(n-i);
        result/=(i+1);
    }
    return result;
}


// Q. You are given N and you have to print the row
// Time Complexity = O(n/2)
// Space Complexity = O(n)
void solution2(int n){
    vector<int> arr(n,0);

    arr[0] = 1;
    arr[n-1] = 1;

    for (int i = 1; i < n/2 +1; i++)
    {
        arr[i] = (arr[i-1]*(n-i)) / i;
        arr[n-i-1] = (arr[i-1]*(n-i)) / i;
    }
    
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << '\t';
    }
    cout << endl;
}


// Q. Given n return the entire pascal triangle upto n
// Time Complexity = O(n2)
// Space Complexity = O(n2)
// use the solution 2 to do this
void solution3(vector<int> &arr, int n){

}





// Q. Given N and R find the element at that position in pascal triangle
int main(){

    int n, r;
    cin >> n >> r;

    cout << solution1(n, r) << endl;
    solution2(n);


    return 0;
}