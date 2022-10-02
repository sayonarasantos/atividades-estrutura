#include <iostream>
using namespace std;

class MinHeap
{
    int* heap;
    int maxSize;
    int heapSize;

    public:
        MinHeap(int maxHeapSize) {
            heapSize = 0;
            maxSize = maxHeapSize - 1;
            heap = new int[maxSize];
        }

        ~MinHeap() {
            delete heap;
            heap = NULL;
        }

        int getParentIndex(int childrenIndex) {
            return (childrenIndex - 1) / 2;
        }

        int getLeftChildrenIndex(int parentIndex) {
            return 2 * parentIndex + 1;
        }

        int getRightChildrenIndex(int parentIndex) {
            return 2 * parentIndex + 2;
        }

        void swapValues(int elementIndex, int parentIndex) {
            int aux = heap[elementIndex];
            heap[elementIndex] = heap[parentIndex];
            heap[parentIndex] = aux;
        }

        void heapify(int elementIndex) {
            int leftIndex = getLeftChildrenIndex(elementIndex);
            int rightIndex = getRightChildrenIndex(elementIndex);
            
            int smallestElementIndex = elementIndex;

            if(heap[leftIndex] < heap[elementIndex])
                smallestElementIndex = leftIndex;

            if(heap[rightIndex] < heap[smallestElementIndex])
                smallestElementIndex = rightIndex;

            swapValues(elementIndex, smallestElementIndex);
        }

        void insertElement(int element) {
            if(heapSize <= maxSize) {
                heapSize++;
                int newElemIndex = heapSize - 1;
                heap[newElemIndex] = element;

                int parentIndex = getParentIndex(newElemIndex);

                while(newElemIndex != 0 && 
                    heap[parentIndex] > heap[newElemIndex]) {
                    
                    swapValues(newElemIndex, parentIndex);

                    newElemIndex = parentIndex;
                    parentIndex = getParentIndex(newElemIndex);
                }
            } else {
                cout << "Element could not be inserted because heap is full." << endl;
            }
        }

        void deleteElement(int element) {
            int elementIndex = searchElement(element);

            if(heapSize > 0) {
                swapValues(elementIndex, heapSize - 1);
                heap[heapSize] = 0;
                heapSize--;

                if(elementIndex < ((heapSize - 1) / 2 + 1))
                    heapify(elementIndex);
            } else {
                cout << "The heap is empty" << endl;
            }
        }

        int searchElement(int element) {
            for(int i = 0; i < heapSize; i++) {
                if(heap[i] == element)
                    return i;
            }

            return -1;
        }

        void printHeap() {
            for(int i = 0; i < heapSize; i++) {
                cout << heap[i] << " ";
            }
            cout << endl;
        }

        void freeHeap() {
            for(int i = heapSize; i > 0; i--) {
                heap[i] = 0;
                heapSize--;
            }
        }
};


int main(int argc, char const *argv[])
{
    MinHeap heap(6);
    heap.insertElement(1);
    heap.insertElement(2);
    heap.insertElement(3);
    heap.insertElement(4);
    heap.insertElement(5);
    heap.insertElement(6);
    heap.insertElement(7);
    
    heap.printHeap();

    heap.deleteElement(4);

    heap.printHeap();

    heap.freeHeap();

    heap.printHeap();

    heap.insertElement(80);
    heap.insertElement(90);

    heap.printHeap();

    return 0;
}
