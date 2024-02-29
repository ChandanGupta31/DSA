#include<iostream>
#include<vector>

using namespace std;


int solution(vector<int> &arr, int n){
    int last = 0;
    int slast = 0;

    if(n>=2)    last = abs(arr[1]-arr[0]);
    for (int i = 2; i < n; i++)
    {
        int temp = last;
        last = min(abs(arr[i]-arr[i-1])+last, abs(arr[i]-arr[i-2])+slast);
        slast = temp;
    }
    return last;
}


// Question Link
// https://www.codingninjas.com/studio/problems/frog-jump_3621012?source=youtube&campaign=striver_dp_videos&leftPanelTabValue=PROBLEM
int main(){

    vector<int> arr = {10,20,30,10};

    cout << solution(arr, arr.size()) << endl;

    return 0;
}