// https://leetcode.com/problems/shortest-unsorted-continuous-subarray/solution/

#include<iostream>
#include<vector>
using namespace std;

pair<int,int> subarraySort(vector<int> ar){
    int smallest = 1000000007, largest = -1000000007;
    int n = ar.size();

    // Edge case
    if(ar[0] > ar[1])
        smallest = min(smallest, ar[0]), largest = max(largest, ar[0]);
    
    for (int i = 1; i < n - 1; i++)
    {
        if(ar[i]>ar[i+1] || ar[i]<ar[i-1]){
            smallest = min(smallest, ar[i]);
            largest = max(largest, ar[i]);
        }
    }

    // Edge case
    if(ar[n-1]< ar[n-2])
        smallest = min(smallest, ar[n-1]), largest = max(largest, ar[n-1]);

    // next step find the right index where smallest and largest lie(subarray)

    if(smallest==1000000007)
        return {-1, -1};

    int L = 0, R = n - 1;

    /*for (int i = 0; i < n; i++)
    {
        if(smallest<ar[i]){
            L = i;
            break;
        }
    } */
    

    /*for (int i = n-1; i>=0;i--){
        if(largest>ar[i]){
            R = i;
            break;
        }
    } */

    while(smallest>=ar[L])
        L++;
    while(largest<=ar[R])
        R--;
        
    return {L, R};
}

int main(){

    vector<int> ar{1, 2, 3, 4, 5, 8, 6, 7, 9, 10, 11};
    auto p = subarraySort(ar);
    cout << p.first << " and " << p.second << endl;

    return 0;
}