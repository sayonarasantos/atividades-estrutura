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
        int size;

        List() {
            head = NULL;
            size = 0;
        }

        int isEmpty() {
            if(head == NULL) {
                return 1;
            } else {
                return 0;
            }
        }

        Node* getNodePtr(int value) {
            for(Node* i = head; i != NULL; i = i->next) {
                if(i->value == value) {
                    return i;
                }
            }

            return NULL;
        }   

        void insertNode(int newValue, Node* currentPtr) {
            Node* newPtr = new Node(newValue);
            size += 1;

            if(isEmpty() == 1) {
                head = newPtr;
            } else{
                if(head->value >= newValue) {
                    newPtr->next = head;
                    head = newPtr;
                } else if(currentPtr->next == NULL) {
                    currentPtr->next = newPtr;
                } else {
                    if(currentPtr->next->value >= newValue) {
                        newPtr->next = currentPtr->next;
                        currentPtr->next = newPtr;
                    } else {
                        insertNode(newValue, currentPtr->next);
                    }
                }
            }

            newPtr = NULL;
        }

        void deleteNode(int value) {
            Node* elemPtr = getNodePtr(value);

            if(elemPtr != NULL) {
                size -= 1;

                if(head == elemPtr) {
                    head = head->next;
                } else {
                    for(Node* i = head; i != NULL; i = i->next) {
                        if(i->next == elemPtr) {
                            i->next = elemPtr->next;
                        }
                    }
                }
            }

            elemPtr = NULL;
        }

        void deleteNodeRecursively(int value, Node* ptr) {
            Node* aux = NULL;

            if(head != NULL) {
                if(head->value == value) {
                    aux = head->next;
                    head = aux;
                } else if(ptr->next != NULL) {
                    if(ptr->next->value == value) {
                        aux = ptr->next->next;
                        ptr->next = aux;
                        size -= 1;
                    }
                    else {
                        deleteNodeRecursively(value, ptr->next);
                    }
                }
            }

            aux = NULL;
        }

        void deleteList() {
            Node* aux = NULL;
            size = 0;

            for(Node* i = head; i != NULL; i = i->next) {                
                if(i->next != NULL) {
                    aux = i;
                    head = i->next;
                    aux = NULL;
                } else {
                    head = NULL;
                }
            }
        }
        

        void printList() {     
            if(head != NULL) {
                for(Node* i = head; i != NULL; i = i->next) {
                    cout << i->value << endl;
                }
            } else {
                cout << "The list is empty." << endl;
            }
        }

        void printListRecursively(Node* ptr) {
            if(head == NULL) {
                cout << "The list is empty." << endl;
            }
            
            if(ptr != NULL) {
                cout << ptr->value << endl;
                printListRecursively(ptr->next);
            }
        }

        // void printListReverse() {
        //    List auxList;
        //    Node* aux;

        //     if(head != NULL) {
        //         for(Node i = head; i != NULL; i = i.next) {
        //             aux = auxList.head;
        //             auxList.head = i;
        //             auxList.head->next = aux;
        //         }
        //     } else {
        //         cout << "The list is empty." << endl;
        //     }

        //     aux = NULL;
        //     auxList.printList();
        // }

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


    // Q2.1
    cout << "# Q2.1) Create empty list. " << endl;
    List listA;
    cout << endl;


    cout << "******* Test functions with empty list *******" << endl;
    cout << endl;


    // Q2.3
    cout << "# Q2.3) Print the list:" << endl;
    listA.printList();
    cout << endl; 


    // Q2.4
    cout << "# Q2.4) Print the list recursively:" << endl;
    listA.printListRecursively(listA.head);
    cout << endl;


    // // Q2.5
    // cout << "# Q2.5) Print the list in reverse order:" << endl;
    // listA.printListReverse();
    // cout << endl;


    // Q2.6
    cout << "# Q2.6) Is list empty? (Returns 1 if empty or 0 if not empty) " << listA.isEmpty() << endl;
    cout << endl;


    // Q2.7
    cout << "# Q2.7) Returns memory address of element 2 or 0 if it doesn't exists: " << listA.getNodePtr(2) << endl;
    cout << endl;


    // Q2.8
    cout << "# Q2.8) Remove element 2. " << endl;
    listA.deleteNode(2);
    cout << "Print the list:" << endl;
    listA.printList();
    cout << endl;


    // Q2.9
    cout << "# Q2.9) Remove element 2 recursively." << endl;
    listA.deleteNodeRecursively(2, listA.head);
    cout << "Print the list:" << endl;
    listA.printList();
    cout << endl;


    // Q2.10
    cout << "# Q2.10) Remove list." << endl;
    listA.deleteList();
    cout << "Print the list:" << endl;
    listA.printList();
    cout << endl;


    cout << "******* Test functions with elements in the list *******" << endl;
    cout << endl;


    // Q2.2
    cout << "# Q2.2) Insert elements 50, 12, 74 and 2." << endl;
    listA.insertNode(50, listA.head);
    listA.insertNode(12, listA.head);
    listA.insertNode(74, listA.head);
    listA.insertNode(2, listA.head);
    cout << endl;


    // Q2.3
    cout << "# Q2.3) Print the list:" << endl;
    listA.printList();
    cout << endl; 


    // Q2.4
    cout << "# Q2.4) Print the list recursively:" << endl;
    listA.printListRecursively(listA.head);
    cout << endl;


    // // Q2.5
    // cout << "# Q2.5) Print the list in reverse order:" << endl;
    // listA.printListReverse();
    // cout << endl;


    // Q2.6
    cout << "# Q2.6) Is list empty? (Returns 1 if empty or 0 if not empty) " << listA.isEmpty() << endl;
    cout << endl;

   
    // Q2.7
    cout << "# Q2.7) Return memory address of element or 0 if it doesn't exists: " << listA.getNodePtr(2) << endl;
    cout << "* Element 2: " << listA.getNodePtr(2) << endl;
    cout << "* Element 12: " << listA.getNodePtr(12) << endl;
    cout << "* Element 6: " << listA.getNodePtr(6) << endl;
    cout << "* Element 74: " << listA.getNodePtr(74) << endl;
    cout << endl;


    // Q2.8
    cout << "# Q2.8) Remove elements: " << endl;
    cout << "Print the initial list:" << endl;
    listA.printList();
    cout << endl;

    cout << "* Remove 2." << endl;
    listA.deleteNode(2);
    cout << "Print the list:" << endl;
    listA.printList();
    cout << endl;

    cout << "* Remove 12." << endl;
    listA.deleteNode(12);
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
    listA.insertNode(4, listA.head);
    listA.insertNode(13, listA.head);
    listA.insertNode(100, listA.head);
    listA.insertNode(1111, listA.head);
    cout << "Print the list:" << endl;
    listA.printList();
    cout << endl;

    
    // Q2.9
    cout << "# Q2.9) Remove elements recursively: " << endl;
    cout << "Print the initial list:" << endl;
    listA.printList();
    cout << endl;

    cout << "* Remove element 13." << endl;
    listA.deleteNodeRecursively(13, listA.head);
    cout << "Print the list:" << endl;
    listA.printList();
    cout << endl;

    cout << "* Remove element 1111." << endl;
    listA.deleteNodeRecursively(1111, listA.head);
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

    cout << "* Remove element 100." << endl;
    listA.deleteNodeRecursively(100, listA.head);
    cout << "Print the list:" << endl;
    listA.printList();
    cout << endl;


    cout << "Insert elements 5, 55 and 14." << endl;
    listA.insertNode(5, listA.head);
    listA.insertNode(55, listA.head);
    listA.insertNode(14, listA.head);
    cout << "Print the list:" << endl;
    listA.printList();
    cout << endl;


    // Q2.10
    cout << "# Q2.10) Remove the list." << endl;
    listA.deleteList();
    cout << "Print the list:" << endl;
    listA.printList();
    cout << endl;


    // Q2.11
    List listB;

    cout << "# Q2.11) Compare lists: (Returns 1 if true or 0 if false)" << endl;
    cout << endl;

    cout << "* The list A:" << endl;
    listA.printList();
    
    cout << "The list B:" << endl;
    listB.printList();
    
    cout << "Is list A equals to list B? " << listA.isEquals(&listB) << endl;
    cout << endl;

    listB.insertNode(5, listB.head);
    listB.insertNode(55, listB.head);

    cout << "* The list A:" << endl;
    listA.printList();
    
    cout << "The list B:" << endl;
    listB.printList();
    
    cout << "Is list A equals to list B? " << listA.isEquals(&listB) << endl;
    cout << endl;

    listA.insertNode(5, listA.head);
    listA.insertNode(55, listA.head);

    cout << "* The list A:" << endl;
    listA.printList();
    
    cout << "The list B:" << endl;
    listB.printList();
    
    cout << "Is list A equals to list B? " << listA.isEquals(&listB) << endl;
    cout << endl;

    listA.insertNode(3, listA.head);

    cout << "* The list A:" << endl;
    listA.printList();
    
    cout << "The list B:" << endl;
    listB.printList();
    
    cout << "Is list A equals to list B? " << listA.isEquals(&listB) << endl;
    cout << endl;

    listB.insertNode(1, listB.head);

    cout << "* The list A:" << endl;
    listA.printList();
    
    cout << "The list B:" << endl;
    listB.printList();
    
    cout << "Is list A equals to list B? " << listA.isEquals(&listB) << endl;
    cout << endl;


    return 0;
}
