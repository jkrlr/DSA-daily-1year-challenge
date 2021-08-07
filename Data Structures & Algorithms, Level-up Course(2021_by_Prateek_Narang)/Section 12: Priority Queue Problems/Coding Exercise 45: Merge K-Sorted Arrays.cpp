// Time = O(Nk * Logk), Space = O(k)
// https://leetcode.com/problems/merge-k-sorted-lists/

#include <iostream>
#include <queue>
#include<vector>
using namespace std;

vector<int> mergeKArrays(vector<vector<int>> arrays){    
    int k = arrays.size();

    // triplet -> element, array_idx, element_idx
    priority_queue < vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    
    vector<int> res;
    
    // initialize the min heap of size k
    for (int i = 0; i < k;i++){
        int element = arrays[i][0];
        int arrayIdx = i;
        int elementIdx = 0;

        pq.push({element, arrayIdx, elementIdx});
    }

    // start popping and pushing
    while(!pq.empty()){
        vector<int> top = pq.top();
        pq.pop();

        int element = top[0];
        int arrayIdx = top[1];
        int elementIdx = top[2];

        res.push_back(element);

        if(elementIdx < arrays[arrayIdx].size()-1){
            int nextElementIdx = elementIdx + 1;
            int nextElement = arrays[arrayIdx][nextElementIdx];

            pq.push({nextElement, arrayIdx, nextElementIdx});
        }
    }
    return res;
}

int main()
{
    vector<vector<int>> arrays = {{10, 15, 20, 30},
                               {2, 5, 8, 14, 24},
                               {0, 11, 60, 90}};

    vector<int> res = mergeKArrays(arrays);

    // output
    for(auto x:res){
        cout << x << " ";
    }
}
