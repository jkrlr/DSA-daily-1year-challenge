class MaxHeap{
    vector<int> maxHeap;
    int heapSize;
    int realSize = 0;
public:    
     MaxHeap(int heapSize) {
        this->heapSize = heapSize;
        maxHeap.resize(heapSize);
    }
public:
    // Function to add an element
    void add(int element) {
        realSize++;
        // If the number of elements in the Heap exceeds the preset heapSize
        // print "Added too many elements" and return
        if (realSize > heapSize) {
            cout<<"Added too many elements!"<<endl;
            realSize--;
            return;
        }
        
        maxHeap[realSize] = element;  // Add the element into the array i.e. Add it to the rightMost child of bottom level
        
        // Now, restore the Heap
        // Bubble it up the current Item if the current Item is greater than it's parent
        int index = realSize;   // Index of the newly added Item
        int parent = index / 2;
        
        // Looking at parent and Ask, "Am I greater than you(parent)"?
        // If yes swap parent ant current Item
        while(index > 1 && maxHeap[index] > maxHeap[parent]){
            swap(maxHeap[index], maxHeap[parent]);
            index = parent;
            parent = index / 2;
        }
    }
public:
    // Get the top element of the Heap
    int top() {
        return maxHeap[1];
    }
public:
    // Delete the top element of the Heap
    void pop() {
        // If the number of elements in the current Heap is 0,
        // print "Don't have any elements" and return a default value
        if (realSize < 1) {
            cout<<"Don't have any element!"<<endl;
            return;
        } 
        
        // When there are still elements in the Heap i.e. realSize >= 1
        maxHeap[1] = maxHeap[realSize]; // Put the last element in the Heap to the top of Heap i.e. Replace the rightMost child of bottom level with the top of heap.
        realSize--;
        
        // Now, restore the Heap
        // Bubble it down the current Item(i.e. top of maxHeap) if the current Item is less than it's left or right child
        int index = 1;
    
        // Bubble it down, until we are not reach at the bottom level
        while (index <= realSize / 2) {
            int left = index * 2;        
            int right = (index * 2) + 1;
            
            // Ask to left and right childs, "Am I smaller than any of you"?
            // If yes, Then swap the parent with the larger value of the left and right child
            if (maxHeap[index] < maxHeap[left] || maxHeap[index] < maxHeap[right]) {
                if (maxHeap[left] > maxHeap[right]) {
                    swap(maxHeap[index], maxHeap[left]);
                    index = left;
                } 
                else {// maxHeap[left] <= maxHeap[right]
                    swap(maxHeap[index], maxHeap[right]);
                    index = right;
                }
            } 
            else 
                break;
        } 
    }
public:
    // Return the number of elements in the Heap
    int size() {
        return realSize;
    }
};

int main(){
    vector<int> input = {0, 100, -500, 50, 2};
    int n = input.size();
    int N = 4*(n+1);
    MaxHeap mh(N);

    for(int i=0; i<n; i++)
        mh.add(input[i]);
    
    cout<<mh.size()<<endl;  // 5
    cout<<mh.top()<<endl;   // 100
    mh.pop();               // Remove 100
    cout<<mh.size()<<endl;  // 4
    cout<<mh.top()<<endl;   // 50
}
