#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

// Time Complexity = O(2n) = O(n)
// Space Complexity = O(n)
void solution(vector<int> &arr, int n){
    vector<int> positive;
    vector<int> negative;

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
    
    if (positive.size() > negative.size())
    {
        for (int i = 0; i < negative.size(); i++)
        {
            arr[2*i] = positive[i];
            arr[2*i+1] = negative[i];
        }
        int index = 2*negative.size();
        for (int i = negative.size(); i < positive.size(); i++)
        {
            arr[index] = positive[i];
            index++;
        }
    }
    else
    {
        for (int i = 0; i < positive.size(); i++)
        {   
            arr[2*i] = positive[i];
            arr[2*i+1] = negative[i];
        }
        int index = 2*positive.size();
        for (int i = positive.size(); i < negative.size(); i++)
        {
            arr[index] = negative[i];
            index++;
        }
    }
}




// Alternate the number in the array and if any type is in excess in the last continuously put them all remaining
int main(){

    vector<int> arr = {1,2,-4,-5,3,6};

    solution(arr, arr.size());
    for (int  i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << '\t';
    }
    cout << endl;

    return 0;
}