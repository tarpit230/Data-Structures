#include<bits/stdc++.h>
using namespace std;

class MaxHeap {
    public:
    vector<int> heap = {90, 36, 17, 25, 26, 7, 1, 2, 3, 19};

    int parent(int index){
        return floor((index-1)/2);
    }

    int leftChild(int index){
        return (2*index + 1);
    }
    
    int rightChild(int index){
        return (2*index + 2);
    }

    // Insert element in max heap
    void insert(int nodeToAdd){
        heap.push_back(nodeToAdd);
        heapifyUp(heap.size()-1);
    }

    void heapifyUp(int index){
        while(index != 0 || parent(index) < index){
            swap(heap[parent(index)], heap[index]);
            index = parent(index);
        }
    }

    // Deleting root node
    void deleteRoot(){
        if(heap.size() == 0) return;
        swap(heap[0], heap[heap.size()-1]);
        heap.pop_back();
        heapifyDown(0); 
    }

    void heapifyDown(int index) {
        int n = heap.size();

        while (true) {
            int left = leftChild(index);
            int right = rightChild(index);
            int largest = index;

            if (left < n && heap[left] > heap[largest]) {
                largest = left;
            }

            if (right < n && heap[right] > heap[largest]) {
                largest = right;
            }

            if (largest == index) {
                break;
            }

            swap(heap[index], heap[largest]);
            index = largest;
        }
    }

    // convert non heap array to heap
    void buildHeap(vector<int> arr){
        heap = arr;
        int lastnonleaf = (heap.size()/2) - 1;
        for(int i=lastnonleaf; i>=0; i--){
            heapifyDown(i);
        }
    }
};