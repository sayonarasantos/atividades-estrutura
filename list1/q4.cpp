#include <iostream>
using namespace std;

class Node 
{
    public:
        int value;
        Node* next;
        
        Node(int nodeValue, Node* nextNode = NULL) {
            value = nodeValue;
            next = nextNode;
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

        bool isEmpty() {
            if(head == NULL) {
                return 1;
            } else {
                return 0;
            }
        }

        // Node* getNodePtr(int value) {
            // Node* aux = NULL;

            // while(!isEmpty()) {
            //     if(aux->value == value) {
            //         return aux;
            //     }

            //     if(aux == tail) {
            //         return NULL;
            //     }

            //     aux = aux->next;             
            // }
        // } 

        void insertNode(int newValue) {
            Node* newPtr = new Node(newValue);
            size += 1;

            if(isEmpty()) {
                newPtr->next = newPtr;
                head = newPtr;
                tail = newPtr;
            } else {
                tail->next = newPtr;
                newPtr->next = head;
                tail = newPtr;
            }
        }

        void deleteNode(int value) {
            Node* aux = NULL;
            Node* currNode = head;

            if(!isEmpty()) {
                if(head->value == value && head == tail) {
                    size -= 1;
                    head = NULL;
                    tail = NULL;
                } else if(head->value == value) {
                    aux = head;
                    tail->next = aux->next;
                    head = aux;
                    size -= 1;
                    aux = NULL;
                } else {
                    while(true) {
                        if(currNode->next != head) {
                            if(currNode->next->value == value) {
                                aux = currNode->next;

                                if(currNode->next == tail) {
                                    tail = currNode;
                                }

                                currNode->next = aux->next;
                                size -= 1;
                                aux = NULL;
                            }
                            
                            currNode = currNode->next;
                        } else {
                            break;
                        }
                    }
                }
            }
        }

        void deleteNodeRecursively(int value, Node* ptr) {
            Node* aux = NULL;

            if(!isEmpty()) {
                if(value == head->value && head == tail) {
                    size -= 1;
                    head = NULL;
                    tail = NULL;
                } else if(value == head->value) {
                    aux = head->next;
                    tail->next = aux;
                    head = aux;
                    size -= 1;
                    aux = NULL;
                } else if(ptr->next != head) {
                    if(ptr->next->value == value) {
                        aux = ptr->next;

                        if(ptr->next == tail) {
                            tail = ptr;
                        }

                        ptr->next = aux->next;
                        size -= 1;
                        aux = NULL;
                    } else {
                        deleteNodeRecursively(value, ptr->next);
                    }
                }
            }
        }

        void deleteList() {
            Node* aux = NULL;

            while(!isEmpty()) {
                size -= 1;
                aux = head;
                head = aux->next;
                aux = NULL;

                if(head == tail) {
                    head = NULL;
                    tail = NULL;
                    break;
                }

            }
        }

        void printList() {

            if(!isEmpty()) {
                Node* aux = head;

                while(true) {
                    cout << aux->value << endl;
                    aux = aux->next;
                    
                    if(aux == head) {
                        break;
                    }

                }
            } else {
                cout << "The list is empty." << endl;
            }
        }

        void printListRecursively(Node* ptr) {
            if(!isEmpty()) {
                if(ptr != tail) {
                    cout << ptr->value << endl;
                    printListRecursively(ptr->next);
                } else {
                    cout << ptr->value << endl;
                }
            } else {
                cout << "The list is empty." << endl;
            }
        }
};


int main(int argc, char const *argv[])
{
    cout << "******* Starting script... *******" << endl;
    cout << endl;


    // Q4.1
    cout << "# Q4.1) Create empty list. " << endl;
    List listA;
    cout << endl;


    cout << "******* Test functions with empty list *******" << endl;
    cout << endl;


    // Q4.3
    cout << "# Q4.3) Print the list:" << endl;
    listA.printList();
    cout << endl; 


    // Q4.4
    cout << "# Q4.4) Print the list recursively:" << endl;
    listA.printListRecursively(listA.head);
    cout << endl;


    // Q4.5
    cout << "# Q4.5) Is list empty? (Returns 1 if empty or 0 if not empty) " << listA.isEmpty() << endl;
    cout << endl;


    // Q4.6
    // cout << "# Q4.6) Returns memory address of element 2 or 0 if it doesn't exists: " << listA.getNodePtr(2) << endl;
    // cout << endl;


    // Q4.7
    cout << "# Q4.7) Remove element 2. " << endl;
    listA.deleteNode(2);
    cout << "Print the list:" << endl;
    listA.printList();
    cout << endl;


    // Q4.8
    cout << "# Q4.8) Remove element 2 recursively." << endl;
    listA.deleteNodeRecursively(2, listA.head);
    cout << "Print the list:" << endl;
    listA.printList();
    cout << endl;


    // Q4.9
    cout << "# Q4.9) Remove list." << endl;
    listA.deleteList();
    cout << "Print the list:" << endl;
    listA.printList();
    cout << endl;


    cout << "******* Test functions with elements in the list *******" << endl;
    cout << endl;


    // Q4.2
    cout << "# Q4.2) Insert elements 50, 12, 74 and 2." << endl;
    listA.insertNode(50);
    listA.insertNode(12);
    listA.insertNode(74);
    listA.insertNode(2);
    cout << endl;


    // Q4.3
    cout << "# Q4.3) Print the list:" << endl;
    listA.printList();
    cout << endl; 


    // Q4.4
    cout << "# Q4.4) Print the list recursively:" << endl;
    listA.printListRecursively(listA.head);
    cout << endl;


    // Q4.5
    cout << "# Q4.6) Is list empty? (Returns 1 if empty or 0 if not empty) " << listA.isEmpty() << endl;
    cout << endl;

   
    // Q4.6
    // cout << "# Q4.6) Return memory address of element or 0 if it doesn't exists: " << endl;
    // cout << "* Element 12: " << listA.getNodePtr(12) << endl;
    // cout << "* Element 2: " << listA.getNodePtr(2) << endl;
    // cout << "* Element 6: " << listA.getNodePtr(6) << endl;
    // cout << "* Element 74: " << listA.getNodePtr(74) << endl;
    cout << endl;


    // Q4.7
    cout << "# Q4.7) Remove elements: " << endl;
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

    
    // Q4.8
    cout << "# Q4.8) Remove elements recursively: " << endl;
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


    // Q4.9
    cout << "# Q4.9) Remove the list." << endl;
    listA.deleteList();
    cout << "Print the list:" << endl;
    listA.printList();
    cout << endl;


    return 0;
}

