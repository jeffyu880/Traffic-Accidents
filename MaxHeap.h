#pragma once
#include<vector>
using namespace std; 

template<typename T>
class MaxHeap {
public:
    //                                                             Constructors and Functions to Deal With Memory
    //-----------------------------------------------------------------------------------------------------------------------------------------------------------------

    //Default Constructor
    MaxHeap() {
        capacity = 1;
        size = 0;
        data = new T[capacity];
    }

    //Constructor
    MaxHeap(int capacity) {
        this->capacity = capacity;
        size = 0;
        data = new T[capacity];
    }

    //Copy Constructor
    MaxHeap(const MaxHeap& rhs) {
        capacity = rhs.capacity;
        size = rhs.size;
        data = new T[capacity];
        for (unsigned int ii = 0; ii < capacity; ii += 1) {
            data[ii] = rhs.data[ii];
        }
    }

    //Overloading Copy Assignement Operator
    MaxHeap<T>& operator=(const MaxHeap<T>& rhs) {
        return *this;
    }

    //Destructor
    ~MaxHeap() {
        delete[] data;
        capacity = 1;
        size = 0;
    }
  


    //                                                                      Heap Functions
    //----------------------------------------------------------------------------------------------------------------------------------------------------------------

        void insert(T val) {
            if (size == capacity) {
                resizeUp();
                data[size] = val;
                size += 1;
                HeapifyUp(size - 1);
            }
            else {
                data[size] = val;
                size += 1;
                HeapifyUp(size - 1);
            }
        }

        T top() {
            return data[0];
        }

        T pop() {
            T temp = data[0];
            remove();
            return temp;
        }


        void MaxKElements(int k, vector<T>& elements) {
            if (k == 0) {
                return;
            }
            else {
                elements.push_back(pop());
                MaxKElements(k - 1, elements);
            }
        }

        unsigned int Size() {
            return size; 
        }

private:
    //                                                                       Utility Functions 
  //-----------------------------------------------------------------------------------------------------------------------------------------------------------------

    void resizeUp() {
        capacity = capacity * 2;
        T* tempArray = new T[capacity];
        for (unsigned int ii = 0; ii < size; ii += 1) {
            tempArray[ii] = data[ii];
        }
        delete[] data;
        data = tempArray;
    }

    void resizeDown() {
        bool resize = false;
        if (capacity % 2 == 0) {
            if (size == (capacity / 2)) {
                resize = true;
            }
        }
        else {
            if ((size - 1) == (capacity / 2)) {
                resize = true;
            }
        }
        if (resize) {
            capacity = capacity / 2;
            T* tempArray = new T[capacity];
            for (unsigned int ii = 0; ii < size - 2; ii += 1) {
                tempArray[ii] = data[ii];
            }
            delete[] data;
            data = tempArray;
            size -= 1;
        }
        else {
            T* tempArray = new T[capacity]; 
            for (unsigned int ii = 0; ii < size - 1; ii += 1) {
                tempArray[ii] = data[ii];
            }
            delete[] data;
            data = tempArray;
            size -= 1;
        }
    }

    void swap(int ii, int jj) {
        T temp = data[ii];
        data[ii] = data[jj];
        data[jj] = temp;
    }

    void HeapifyUp(int index) {
        int parent = (index - 1) / 2;

        if (data[parent] > 0) {
            if (data[index] > data[parent]) {
                swap(index, parent);
                HeapifyUp(parent);
            }
        }
    }

    void HeapifyDown(int index) {
        int largest = index;
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;

        if (leftChild < size && data[leftChild] > data[largest]) {
            largest = leftChild;
        }

        if (rightChild < size && data[rightChild] > data[largest]) {
            largest = rightChild;
        }

        if (largest != index) {
            swap(index, largest);
            HeapifyDown(largest);
        }
    }

    void remove() {
        T lastVal = data[size - 1];
        data[0] = lastVal;
        resizeDown();
        HeapifyDown(0);
    }
    //Variable Declaration
    T* data;
    unsigned int capacity;
    unsigned int size;
};
