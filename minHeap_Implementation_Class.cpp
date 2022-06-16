// https://leetcode.com/playground/oV6Thz5S

// Heap is a Complete Binary Tree, In which we fill the elments from Left--->Right and Top--->Bottom manner.

/* 
A common misconception is that a Heap is the same as a Priority Queue, which is not true. 
A priority queue is an abstract data type(ADT), while a Heap is a data structure. 
Therefore, a Heap is not a Priority Queue, but a way to implement a Priority Queue.
*/

class MinHeap{
    vector<int> minHeap;
    int heapSize;
    int realSize = 0;
public:    
     MinHeap(int heapSize) {
        this->heapSize = heapSize;
        minHeap.resize(heapSize);
    }
public:
    // Function to add an element - O(LogN)
    void add(int element) {
        realSize++;
        // If the number of elements in the Heap exceeds the preset heapSize
        // print "Added too many elements" and return
        if (realSize > heapSize) {
            cout<<"Added too many elements!"<<endl;
            realSize--;
            return;
        }
        
        minHeap[realSize] = element;  // Add the element into the array i.e. Add it to the rightMost child of bottom level
        
        // Now, restore the Heap
        // Bubble it up the current Item if the current Item is smaller than it's parent
        int index = realSize;   // Index of the newly added Item
        int parent = index / 2;
        
        // Looking at parent and Ask, "Am I less than you(parent)"?
        // If yes swap parent ant current Item
        while(index > 1 && minHeap[index] < minHeap[parent]){
            swap(minHeap[index], minHeap[parent]);
            index = parent;
            parent = index / 2;
        }
    }
public:
    // Get the top element of the Heap - O(1)
    int top() {
        return minHeap[1];
    }
public:
    // Delete the top element of the Heap - O(LogN)
    void pop() {
        // If the number of elements in the current Heap is 0,
        // print "Don't have any elements" and return a default value
        if (realSize < 1) {
            cout<<"Don't have any element!"<<endl;
            return;
        } 
        
        // When there are still elements in the Heap i.e. realSize >= 1
        minHeap[1] = minHeap[realSize]; // Put the last element in the Heap to the top of Heap i.e. Replace the rightMost child of bottom level with the top of heap.
        realSize--;
        
        // Now, restore the Heap
        // Bubble it down the current Item(i.e. top of minHeap) if the current Item is greater than it's left or right child
        int index = 1;
    
        // Bubble it down, until we are not reach at the bottom level
        while (index <= realSize / 2) {
            int left = index * 2;        
            int right = (index * 2) + 1;
            
            // Ask to left and right childs, "Am I larger than any of you"?
            // If yes, Then swap the parent with the smaller value of the left and right child
            if (minHeap[index] > minHeap[left] || minHeap[index] > minHeap[right]) {
                if (minHeap[left] < minHeap[right]) {
                    swap(minHeap[index], minHeap[left]);
                    index = left;
                } 
                else {// minHeap[left] >= minHeap[right]
                    swap(minHeap[index], minHeap[right]);
                    index = right;
                }
            } 
            else 
                break;
        } 
    }
public:
    // Return the number of elements in the Heap - O(1)
    int size() {
        return realSize;
    }
};

int main(){
    vector<int> input = {0, 4, -500, 1, 2};
    int n = input.size();
    int N = 4*(n+1);
    MinHeap mh(N);

    for(int i=0; i<n; i++)
        mh.add(input[i]);
    
    cout<<mh.size()<<endl;  // 5
    cout<<mh.top()<<endl;   // -500
    mh.pop();               // Remove -500
    cout<<mh.size()<<endl;  // 4
    cout<<mh.top()<<endl;   // 0
}                         
