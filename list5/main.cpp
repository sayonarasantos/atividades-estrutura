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
            maxSize = maxHeapSize;
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

        void swapValues(int elementIndex1, int elementIndex2) {
            int aux = heap[elementIndex1];
            heap[elementIndex1] = heap[elementIndex2];
            heap[elementIndex2] = aux;
        }

        void heapify(int elementIndex) {
            int parentIndex = getParentIndex(elementIndex);
            int aux = elementIndex;

            while(elementIndex != 0 && 
                heap[parentIndex] > heap[elementIndex]) {
                
                swapValues(elementIndex, parentIndex);

                elementIndex = parentIndex;
                parentIndex = getParentIndex(elementIndex);
                aux = elementIndex;
            }

            if(aux < ((heapSize - 1) / 2 + 1)) {
                for(int i = elementIndex; i < heapSize; i++) {
                    int leftIndex = getLeftChildrenIndex(i);
                    int rightIndex = getRightChildrenIndex(i);
                    
                    int smallestElementIndex = i;

                    if(leftIndex < heapSize && heap[leftIndex] < heap[i]) {
                        smallestElementIndex = leftIndex;
                    }

                    if(rightIndex < heapSize && heap[rightIndex] < heap[smallestElementIndex]) {
                        smallestElementIndex = rightIndex;
                    }

                    swapValues(i, smallestElementIndex);
                }
            }            
        }

        void insertElement(int element) {
            if(heapSize < maxSize) {
                heapSize++;
                int newElemIndex = heapSize - 1;
                heap[newElemIndex] = element;

                heapify(newElemIndex);
            } else {
                cout << "Element could not be inserted because heap is full." << endl;
            }
        }

        void deleteElement(int element) {
            int elementIndex = searchElement(element);

            if(elementIndex == -1) {
                cout << "The element does not exist." << endl;
            }
            else if(heapSize > 0) {
                swapValues(elementIndex, heapSize - 1);
                heap[heapSize-1] = 0;
                heapSize--;

                if(elementIndex < ((heapSize - 1) / 2 + 1))
                    heapify(elementIndex);
            } else {
                cout << "The heap is empty" << endl;
            }
        }

        void changeValue(int element, int newElement) {
            int elementIndex = searchElement(element);

            if(elementIndex == -1) {
                cout << "The element does not exist." << endl;
            }
            else {
                heap[elementIndex] = newElement;
                heapify(elementIndex);
            }
        }

        int searchElement(int element) {
            for(int i = 0; i < heapSize; i++) {
                if(heap[i] == element) {
                    return i;
                }
            }

            return -1;
        }

        void printHeap() {
            if(heapSize == 0)
                cout << "The heap is empty" << endl;

            for(int i = 0; i < heapSize; i++) {
                cout << heap[i] << " ";
            }

            cout << endl;
        }

        void freeHeap() {
            for(int i = heapSize - 1; i >= 0; i--) {
                heap[i] = 0;
                heapSize--;
            }
        }
};


int main(int argc, char const *argv[])
{
    cout << "******* Starting script... *******" << endl;
    cout << endl;


    // Q5.1
    cout << "# Create a Min Heap." << endl;
    cout << endl;

    MinHeap heap(6);


    // Q5.2
    cout << "# Insert elements:" << endl;

    heap.insertElement(2);
    heap.insertElement(4);
    heap.insertElement(5);
    heap.insertElement(9);
    heap.insertElement(11);
    heap.insertElement(15);
    heap.printHeap();
    cout << endl;

    cout << "Try to insert element with full heap:" << endl;
    heap.insertElement(7);
    heap.printHeap();
    cout << endl;


    // Q5.3
    cout << "# Search for elements:" << endl;
    cout << "(-1 = the element does not exist, element index = the element exists)" << endl;

    cout << "- Element 5: " << heap.searchElement(5) << endl;
    cout << "- Element 8: " << heap.searchElement(8) << endl;

    cout << endl;


    // Q5.4
    cout << "# Remove elements:" << endl;

    cout << "- Element 4:" << endl;
    heap.deleteElement(4);
    heap.printHeap();
    cout << endl;

    cout << "- Element 90:" << endl;
    heap.deleteElement(90);
    heap.printHeap();
    cout << endl;


    // Q5.5
    cout << "# Change element values:" << endl;

    cout << "- Element 5 to 1:" << endl;
    heap.changeValue(5, 1);
    heap.printHeap();
    cout << endl;

    cout << "- Element 11 to 6:" << endl;
    heap.changeValue(11, 6);
    heap.printHeap();
    cout << endl;


    // Q5.6
    cout << "# Free Heap:" << endl;

    heap.freeHeap();
    heap.printHeap();

    cout << "Insert new elements:" << endl;
    heap.insertElement(80);
    heap.insertElement(90);
    heap.printHeap();

    return 0;
}
