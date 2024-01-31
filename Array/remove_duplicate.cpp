#include<iostream>
#include<vector>

using namespace std;

int main(){
    vector<int> v = {1,2,3,3,3,4,5,6,6,8,8,9};
    int i=0;

    for (int j = 1; j < v.size(); j++)
    {
        if (v[j]!=v[i])
        {
            v[i+1] = v[j];
            i++;
        }
        
    }

    cout << "Total Unique elements are " << i+1 << endl;
    
    return 0;
}