// Time = O(NLogN), Space = O(N)

#include <iostream>
#include <queue>
using namespace std;

int JoinRopes(int ropes[], int n)
{
    priority_queue<int, vector<int>, greater<int>> min_heap(ropes, ropes + n); // min heap
    int cost = 0;

    while (min_heap.size() > 1){
        int A = min_heap.top();
        min_heap.pop();

        int B = min_heap.top();
        min_heap.pop();

        int newRope = A + B;
        cost += newRope;
        min_heap.push(newRope);
    }

    return cost;
}

int main()
{
    int ropes[] = {4, 3, 2, 6};
    int n = 4;

    cout << JoinRopes(ropes, n) << endl;
}
