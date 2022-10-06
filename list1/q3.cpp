#include <iostream>
using namespace std;

class Node 
{
    public:
        int value;
        Node* next;
        Node* prev;
        
        Node(int nodeValue, Node* nextNode = NULL, Node* prevNode = NULL) {
            value = nodeValue;
            next = nextNode;
            prev = prevNode;
        }
};

class List
{
    public:
        Node* head;
        Node* tail;
        int size;

        List() {
            head = NULL;
            tail = NULL;
            size = 0;
        }

        ~List() {
            deleteList();
        }

        int isEmpty() {
            if(head == NULL) {
                return 1;
            }
            
            return 0;
        }

        Node* getNodePtr(int value) {
            for(Node* i = head; i != NULL; i = i->next) {
                if(i->value == value) {
                    return i;
                }
            }

            return NULL;
        } 

        void insertNode(int newValue) {
            Node* newPtr = new Node(newValue);
            size += 1;

            if(isEmpty()) {
                head = newPtr;
                tail = newPtr;
            } else {
                if(head->value >= newValue) {
                    head->prev = newPtr;
                    newPtr->next = head;
                    head = newPtr;
                } else if(tail->value <= newValue) {
                    tail->next = newPtr;
                    newPtr->prev = tail;
                    tail = newPtr;
                } else {
                    Node* currentPtr = head->next;

                    while(true) {
                        if(currentPtr == NULL) {
                            break;
                        } else if(currentPtr->value >= newValue) {
                            currentPtr->prev->next = newPtr;
                            currentPtr->prev = newPtr;
                            newPtr->next = currentPtr;
                            newPtr->prev = currentPtr->prev;

                            break;
                        } 

                        currentPtr = currentPtr->next;
                    }
                }
            }
        }

        void deleteNode(int value) {
            Node* elemPtr = getNodePtr(value);

            if(elemPtr != NULL) {
                size -= 1;

                if(elemPtr == head && elemPtr == tail) {
                    delete elemPtr;
                    head = NULL;
                    tail = NULL;
                } else if(elemPtr == head) {
                    elemPtr->next->prev = NULL;
                    head = elemPtr->next;
                    delete elemPtr;
                } else if(elemPtr == tail) {
                    elemPtr->prev->next = NULL;
                    tail = elemPtr->prev;
                    delete elemPtr;
                } else {
                    elemPtr->prev->next = elemPtr->next;
                    elemPtr->next->prev = elemPtr->prev;
                    delete elemPtr;
                }
            }

            elemPtr = NULL;
        }

        void deleteNodeRecursively(int value, Node* ptr) {
            Node* aux = NULL;

            if(!isEmpty()) {               
                if(value == head->value && value == tail->value) {
                    head = NULL;
                    tail = NULL;
                    size -= 1;
                } else if(value == head->value) {
                    aux = head->next;
                    head->next->prev = NULL;
                    head = aux;
                    size -= 1;
                } else if(value == tail->value) {
                    aux = tail->prev;
                    tail->prev->next = NULL;
                    tail = aux;
                    size -= 1;                    
                } else if(ptr->next != NULL) {
                    if(ptr->next->value == value) {
                        aux = ptr->next->next;
                        ptr->next->next->prev = NULL;
                        ptr->next = aux;
                        size -= 1;
                    } else {
                        deleteNodeRecursively(value, ptr->next);
                        delete aux;
                        aux = NULL;
                    }
                }
            }
        }

        void deleteList() {
            Node* aux = NULL;
            size = 0;

            while(!isEmpty()) {
                aux = head;
                head = aux->next;
                delete aux;
                aux = NULL;
            }
        }

        void printList() {
            if(!isEmpty()) {
                for(Node* i = head; i != NULL; i = i->next) {
                    cout << i->value << endl;
                }
            } else {
                cout << "The list is empty." << endl;
            }
        }

        void printListRecursively(Node* ptr) {
            if(isEmpty()) {
                cout << "The list is empty." << endl;
            }
            
            if(ptr != NULL) {
                cout << ptr->value << endl;
                printListRecursively(ptr->next);
            }
        }

        void printListReverse() {
            if(!isEmpty()) {
                for(Node* i = tail; i != NULL; i = i->prev) {
                    cout << i->value << endl;
                }
            } else {
                cout << "The list is empty." << endl;
            }
        }

        bool isEquals(List* otherList) {
            Node* currListNode = head;
            Node* otherListNode = otherList->head;

            if(size != otherList->size) {
                return false;
            }

            while(true) {
                if(currListNode == NULL && otherListNode == NULL) {
                    return true;
                } else if(currListNode->value != otherListNode->value) {
                    return false;
                }

                currListNode = currListNode->next;
                otherListNode = otherListNode->next;
            }
        }
};


int main(int argc, char const *argv[])
{
    cout << "******* Starting script... *******" << endl;
    cout << endl;


    // Q3.1
    cout << "# Q3.1) Create empty list. " << endl;
    List listA;
    cout << endl;


    cout << "******* Test functions with empty list *******" << endl;
    cout << endl;


    // Q3.3
    cout << "# Q3.3) Print the list:" << endl;
    listA.printList();
    cout << endl; 


    // Q3.4
    cout << "# Q3.4) Print the list recursively:" << endl;
    listA.printListRecursively(listA.head);
    cout << endl;


    // Q3.5
    cout << "# Q3.5) Print the list in reverse order:" << endl;
    listA.printListReverse();
    cout << endl;


    // Q3.6
    cout << "# Q3.6) Is list empty? (Returns 1 if empty or 0 if not empty) " << listA.isEmpty() << endl;
    cout << endl;


    // Q3.7
    cout << "# Q3.7) Returns memory address of element 2 or 0 if it doesn't exists: " << listA.getNodePtr(2) << endl;
    cout << endl;


    // Q3.8
    cout << "# Q3.8) Remove element 2. " << endl;
    listA.deleteNode(2);
    cout << "Print the list:" << endl;
    listA.printList();
    cout << endl;


    // Q3.9
    cout << "# Q3.9) Remove element 2 recursively." << endl;
    listA.deleteNodeRecursively(2, listA.head);
    cout << "Print the list:" << endl;
    listA.printList();
    cout << endl;


    // Q3.10
    cout << "# Q3.10) Remove list." << endl;
    listA.deleteList();
    cout << "Print the list:" << endl;
    listA.printList();
    cout << endl;


    cout << "******* Test functions with elements in the list *******" << endl;
    cout << endl;


    // Q3.2
    cout << "# Q3.2) Insert elements 50, 12, 74 and 2." << endl;
    listA.insertNode(50);
    listA.insertNode(12);
    listA.insertNode(74);
    listA.insertNode(2);
    cout << endl;


    // Q3.3
    cout << "# Q3.3) Print the list:" << endl;
    listA.printList();
    cout << endl; 


    // Q3.4
    cout << "# Q3.4) Print the list recursively:" << endl;
    listA.printListRecursively(listA.head);
    cout << endl;


    // Q3.5
    cout << "# Q3.5) Print the list in reverse order:" << endl;
    listA.printListReverse();
    cout << endl;


    // Q3.6
    cout << "# Q3.6) Is list empty? (Returns 1 if empty or 0 if not empty) " << listA.isEmpty() << endl;
    cout << endl;

   
    // Q3.7
    cout << "# Q3.7) Return memory address of element or 0 if it doesn't exists: " << endl;
    cout << "* Element 12: " << listA.getNodePtr(12) << endl;
    cout << "* Element 2: " << listA.getNodePtr(2) << endl;
    cout << "* Element 6: " << listA.getNodePtr(6) << endl;
    cout << "* Element 74: " << listA.getNodePtr(74) << endl;
    cout << endl;


    // Q3.8
    cout << "# Q3.8) Remove elements: " << endl;
    cout << "Print the initial list:" << endl;
    listA.printList();
    cout << endl;

    cout << "* Remove 12." << endl;
    listA.deleteNode(12);
    cout << "Print the list:" << endl;
    listA.printList();
    cout << endl;

    cout << "* Remove 2." << endl;
    listA.deleteNode(2);
    cout << "Print the list:" << endl;
    listA.printList();
    cout << endl;

    cout << "* Remove 6." << endl;
    listA.deleteNode(6);
    cout << "Print the list:" << endl;
    listA.printList();
    cout << endl;

    cout << "* Remove 74." << endl;
    listA.deleteNode(74);
    cout << "Print the list:" << endl;
    listA.printList();
    cout << endl;

    cout << "* Remove 50." << endl;
    listA.deleteNode(50);
    cout << "Print the list:" << endl;
    listA.printList();
    cout << endl;
    

    cout << "Insert elements 4, 100, 13 and 1111." << endl;
    listA.insertNode(4);
    listA.insertNode(13);
    listA.insertNode(100);
    listA.insertNode(1111);
    cout << "Print the list:" << endl;
    listA.printList();
    cout << endl;

    
    // Q3.9
    cout << "# Q3.9) Remove elements recursively: " << endl;
    cout << "Print the initial list:" << endl;
    listA.printList();
    cout << endl;

    cout << "* Remove element 13." << endl;
    listA.deleteNodeRecursively(13, listA.head);
    cout << "Print the list:" << endl;
    listA.printList();
    cout << endl;

    cout << "* Remove element 6." << endl;
    listA.deleteNodeRecursively(6, listA.head);
    cout << "Print the list:" << endl;
    listA.printList();
    cout << endl;

    cout << "* Remove element 4." << endl;
    listA.deleteNodeRecursively(4, listA.head);
    cout << "Print the list:" << endl;
    listA.printList();
    cout << endl;

    cout << "* Remove element 1111." << endl;
    listA.deleteNodeRecursively(1111, listA.head);
    cout << "Print the list:" << endl;
    listA.printList();
    cout << endl;

    cout << "* Remove element 100." << endl;
    listA.deleteNodeRecursively(100, listA.head);
    cout << "Print the list:" << endl;
    listA.printList();
    cout << endl;


    cout << "Insert elements 5, 55 and 14." << endl;
    listA.insertNode(5);
    listA.insertNode(55);
    listA.insertNode(14);
    cout << "Print the list:" << endl;
    listA.printList();
    cout << endl;


    // Q3.10
    cout << "# Q3.10) Remove the list." << endl;
    listA.deleteList();
    cout << "Print the list:" << endl;
    listA.printList();
    cout << endl;


    // Q3.11
    List listB;

    cout << "# Q3.11) Compare lists: (Returns 1 if true or 0 if false)" << endl;
    cout << endl;

    cout << "* The list A:" << endl;
    listA.printList();
    
    cout << "The list B:" << endl;
    listB.printList();
    
    cout << "Is list A equals to list B? " << listA.isEquals(&listB) << endl;
    cout << endl;

    listB.insertNode(5);
    listB.insertNode(55);

    cout << "* The list A:" << endl;
    listA.printList();
    
    cout << "The list B:" << endl;
    listB.printList();
    
    cout << "Is list A equals to list B? " << listA.isEquals(&listB) << endl;
    cout << endl;

    listA.insertNode(5);
    listA.insertNode(55);

    cout << "* The list A:" << endl;
    listA.printList();
    
    cout << "The list B:" << endl;
    listB.printList();
    
    cout << "Is list A equals to list B? " << listA.isEquals(&listB) << endl;
    cout << endl;

    listA.insertNode(3);

    cout << "* The list A:" << endl;
    listA.printList();
    
    cout << "The list B:" << endl;
    listB.printList();
    
    cout << "Is list A equals to list B? " << listA.isEquals(&listB) << endl;
    cout << endl;

    listB.insertNode(1);

    cout << "* The list A:" << endl;
    listA.printList();
    
    cout << "The list B:" << endl;
    listB.printList();
    
    cout << "Is list A equals to list B? " << listA.isEquals(&listB) << endl;
    cout << endl;


    return 0;
}

