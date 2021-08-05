#include<iostream>
#include<queue>
using namespace std;

class Compare{
public:
    bool operator()(int a, int b){
        return a > b;
    }
};

int main(){
    int arr[] = {10, 15, 20, 13, 6, 90};
    int n = sizeof(arr) / sizeof(int);

    // priority_queue<int> heap;  // By default this is max_heap
    // priority_queue<int, vector<int>, greater<int>> heap;   // min_heap , greater<int> is in-built comparator which reverse the comparision
    priority_queue<int, vector<int>, Compare> heap; // heap using own custom comparator

    for(int x:arr){
        heap.push(x);
    }

    while(!heap.empty()){
        cout << heap.top() << endl;
        heap.pop();
    }
}