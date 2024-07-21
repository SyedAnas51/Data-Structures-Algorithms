#include <iostream>
#include <algorithm>

using namespace std;

class MinHeap
{
public:
    MinHeap(int capacity) : capacity(capacity), heapSize(0)
    {
        heap = new int[capacity + 1]; // +1 for 1-based indexing
    }

    ~MinHeap()
    {
        delete[] heap;
    }

    void insert(int value)
    {
        if (heapSize >= capacity)
        {
            throw runtime_error("Heap is full");
        }

        heap[++heapSize] = value; // Increment heapSize before inserting
        minHeapifyUp(heapSize);
    }

    int getRoot() const
    {
        if (heapSize == 0)
        {
            throw runtime_error("Heap is empty");
        }
        return heap[1];
    }

private:
    int *heap;
    int capacity;
    int heapSize;

    void minHeapifyUp(int index)
    {
        while (index > 1)
        {
            int parent = index / 2;
            if (heap[index] < heap[parent])
            {
                swap(heap[index], heap[parent]);
                index = parent;
            }
            else
            {
                break;
            }
        }
    }

    void minHeapifyDown(int index)
    {
        int left = 2 * index;
        int right = 2 * index + 1;
        int smallest = index;

        if (left <= heapSize && heap[left] < heap[smallest])
        {
            smallest = left;
        }
        if (right <= heapSize && heap[right] < heap[smallest])
        {
            smallest = right;
        }
        if (smallest != index)
        {
            swap(heap[index], heap[smallest]);
            minHeapifyDown(smallest);
        }
    }
};

class MaxHeap
{
public:
    MaxHeap(int capacity) : capacity(capacity), heapSize(0)
    {
        heap = new int[capacity + 1]; 
    }

    ~MaxHeap()
    {
        delete[] heap;
    }

    void insert(int value)
    {
        if (heapSize >= capacity)
        {
            throw runtime_error("Heap is full");
        }

        heap[++heapSize] = value; // Increment heapSize before inserting
        maxHeapifyUp(heapSize);
    }

    int getRoot() const
    {
        if (heapSize == 0)
        {
            throw runtime_error("Heap is empty");
        }
        return heap[1];
    }

private:
    int *heap;
    int capacity;
    int heapSize;

    void maxHeapifyUp(int index)
    {
        while (index > 1)
        {
            int parent = index / 2;
            if (heap[index] > heap[parent])
            {
                swap(heap[index], heap[parent]);
                index = parent;
            }
            else
            {
                break;
            }
        }
    }

    void maxHeapifyDown(int index)
    {
        int left = 2 * index;
        int right = 2 * index + 1;
        int largest = index;

        if (left <= heapSize && heap[left] > heap[largest])
        {
            largest = left;
        }
        if (right <= heapSize && heap[right] > heap[largest])
        {
            largest = right;
        }
        if (largest != index)
        {
            swap(heap[index], heap[largest]);
            maxHeapifyDown(largest);
        }
    }
};

int main()
{
    MinHeap minHeap(10);
    MaxHeap maxHeap(10);

    minHeap.insert(3);
    minHeap.insert(1);
    minHeap.insert(6);
    minHeap.insert(5);
    minHeap.insert(9);
    minHeap.insert(8);

    maxHeap.insert(3);
    maxHeap.insert(1);
    maxHeap.insert(6);
    maxHeap.insert(5);
    maxHeap.insert(9);
    maxHeap.insert(8);

    cout << "Min Heap root: " << minHeap.getRoot() << endl;
    cout << "Max Heap root: " << maxHeap.getRoot() << endl;

    return 0;
}
