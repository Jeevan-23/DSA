#include <iostream>
#include <vector>
using namespace std;

class PriorityQueue
{
private:
    vector<int> heap;

    // Helper function to move element up to maintain max-heap property
    void heapifyUp(int index)
    {
        while (index > 0 && heap[index] > heap[(index - 1) / 2])
        {
            swap(heap[index], heap[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    }

    // Helper function to move element down to maintain max-heap property
    void heapifyDown(int index)
    {
        int largest = index;
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;

        if (leftChild < heap.size() && heap[leftChild] > heap[largest])
        {
            largest = leftChild;
        }
        if (rightChild < heap.size() && heap[rightChild] > heap[largest])
        {
            largest = rightChild;
        }
        if (largest != index)
        {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    // Insert element into the priority queue
    void push(int element)
    {
        heap.push_back(element);
        heapifyUp(heap.size() - 1);
    }

    // Remove and return the top (largest) element
    int pop()
    {
        if (heap.empty())
        {
            throw out_of_range("Priority Queue is empty");
        }
        int top = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty())
        {
            heapifyDown(0);
        }
        return top;
    }

    // Get the top element without removing it
    int top() const
    {
        if (heap.empty())
        {
            throw out_of_range("Priority Queue is empty");
        }
        return heap[0];
    }

    // Check if the priority queue is empty
    bool empty() const
    {
        return heap.empty();
    }

    // Get the size of the priority queue
    int size() const
    {
        return heap.size();
    }
};

int main()
{
    PriorityQueue pq;
    pq.push(10);
    pq.push(20);
    pq.push(5);
    pq.push(30);

    cout << "Max-Heap Priority Queue:" << endl;
    while (!pq.empty())
    {
        cout << pq.pop() << " ";
    }
    return 0;
}
