#include<iostream>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;

// TIme Complexity = O(2n) = O(n)
// Space Complexity = O(n)
void solution(vector<int> &arr, int n){
    vector<int> positive = {};
    vector<int> negative = {};

    for (int i = 0; i < n; i++)
    {
        if (arr[i]>0)
        {
            positive.push_back(arr[i]);
        }
        else
        {
            negative.push_back(arr[i]);
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        if (i%2==0)
        {
            arr[i] = positive[i/2];
        }
        else
        {
            arr[i] = negative[i/2];
        }
    }
}


// Rearrange the elements of array alternate positive and negative element
int main(){

    vector<int> arr = {3,1,-2,-5,2,-4};

    solution(arr, arr.size());

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << '\t';
    }
    cout << endl;

    return 0;
}