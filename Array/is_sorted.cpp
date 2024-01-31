#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> v = {1,2,3,4,5,6,7,8,9};
    bool flag = true;

    for (int i = 0; i < v.size()-1; i++)
    {
        if(v[i]>v[i+1]){
            flag = false;
            break;
        }
    }

    cout << flag << endl;
    
    return 0;
}