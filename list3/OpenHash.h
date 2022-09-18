#ifndef OPENHASH_H_
#define OPENHASH_H_
#include "SimpleList.h"

class OpenHash
{
    public:
        int size;
        List* hash;
    
        OpenHash(int hashSize) {
            size = hashSize;
            hash = new List[size];
        }
    
        void addElement(int elem) {
            int index = elem % size;
            hash[index].addNode(elem);
            cout << "Element added." << endl;
        }

        void elementExists(int elem) {
            int index = elem % size;

            if(hash[index].getNodePtr(elem)) {
                cout << "Element exist." << endl;
            } else {
                cout << "Element does not exist." << endl;
            }
        }

        void deleteElement(int elem) {
            int index = elem % size;

            if(hash[index].deleteNode(elem)) {
                cout << "Element deleted." << endl;
            } else {
                cout << "Element not found." << endl;
            }

        }

        void deleteHash() {
            for(int i=0; i < size; i++) {
                hash[i].deleteList();
            }

            cout << "Hash deleted." << endl;
        }
};

#endif