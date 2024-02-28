#include<iostream>
#include<vector>
using namespace std;


int possibleWays(int stairs){
    if(stairs==0 || stairs==1)   return 1;
    int chooseOne = possibleWays(stairs-1);
    int chooseTwo = possibleWays(stairs-2);
    return chooseOne + chooseTwo;
}


int optimal(int stairs){
    int pre1 = 1;
    int pre2 = 1;

    for(int i=2; i<=stairs; i++){
        int temp = pre1;
        pre1+=pre2;
        pre2 = temp;
    }

    return pre1;
}


int main(){
    int stairs;
    cin >> stairs;

    vector<int> arr(stairs+1, -1);

    cout << possibleWays(stairs) << endl;
    cout << optimal(stairs) << endl;

    return 0;
}