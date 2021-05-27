#include<iostream>
#include<vector>
using namespace std;

int main(){
    //Demo Vector
    //vector<int> arr = {1, 2, 10, 12, 15};

    //Fill Constructor
    // vector<int> visited(100, 0);

    //Fill Constructor
    vector<int> arr(10, 7);

    // Pop_back
    arr.pop_back();

    // Push_back in O(1)
    arr.push_back(16);

    // Print the all elements
    for(int num :arr)
        cout << num << endl;
        
    /*for (int i = 0; i < arr.size();i++)
        cout << arr[i] << endl;*/


    // Size of the vector(No. of elements)
    cout << arr.size() << endl;

    // Capacity of the vector
    cout << arr.capacity() << endl;

    return 0;
}