#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> v ={5,7,9,2,4,2,3,6,5,8,9,5,2,4,5,8,6};
    int largest = 0, s_largest = 0;

    for (int i = 0; i < v.size(); i++)
    {
        if (v[i]>largest)
        {
            s_largest = largest;
            largest = v[i];
        }
        else if (v[i]>s_largest && v[i]<largest)
        {
            s_largest = v[i];
        }    
        
    }

    cout << s_largest << endl;
    
    return 0;
}