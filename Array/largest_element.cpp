#include<iostream>
#include<vector>
using namespace std;

int main(){

    vector<int> v = {5,4,7,9,5,40,2,1,3,6,4,7,8,9,5};
    int largest = 0;

    for (int i = 0; i < v.size(); i++)
    {
        if (v[i]>largest)
        {
            largest = v[i];
        }
        
    }
    
    cout << largest << endl;
    return 0;
}