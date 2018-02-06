#include <iostream>

using namespace std;

void swap(int* x, int* y);

class minHeap{
    int* node;
    int capacity;
    int heap_size;
public:
    minHeap(int capacity);
 
    void percolateDown(int i);
    int parent(int i) {return (i-1)/2;}  // index of parent
    int left(int i) {return 2*i + 1;}  // index of left child
    int right(int i) {return 2*i + 2;}  // index of tight child
    int deleteMin();
    void decreaseKey(int i, int new_key);
    int getMin() {return node[0];} // return the root
    void deleteKey(int i);
    void insert(int k);
}

minHeap::minHeap(int cap){
    heap_size = 0;
    capacity = cap;
    node = new int[cap];
}

void swap(int* x, int* y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void minHeap::percolateDown(int i){
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (node[l] < node[i] && l < heap_size) {smallest = l;}
    if (node[r] < node[smallest] && r < heap_size) {smallest = r;}
    if (smallest != i){
        swap(&node[i], &node[smallest]);
        percolateDown(smallest);
    }
}

void minHeap::deleteMin(){
    
}
