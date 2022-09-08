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

        List() {
            head = NULL;
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

        void insertNode(int value) {
            Node* ptr = new Node(value);

            if(isEmpty() == 1) {
                head = ptr;
            } else {
                ptr->next = head;
                head = ptr;
            }

            ptr = NULL;
        }

        void deleteNode(int value) {
            Node* elemPtr = getNodePtr(value);

            if(elemPtr != NULL) {
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
            if(ptr != NULL) {
                cout << ptr->value << endl;
                printListRecursively(ptr->next);
            }
        }

        void printListReverse() {
            List auxList;
            Node* aux = head;

            if(head != NULL) {
                for(Node* i = head; i != NULL; i = i->next) {
                    auxList.insertNode(i->value);
                }
            }

            auxList.printList();
        }
};


int main(int argc, char const *argv[])
{
    cout << "******* Starting script... *******" << endl;
    cout << endl;


    // Q1.1
    cout << "# Q1.1) Creating empty list.. " << endl;
    List myList;
    cout << endl;


    cout << "******* Test functions with empty list *******" << endl;
    cout << endl;


    // Q1.3
    cout << "# Q1.3) Print the list:" << endl;
    myList.printList();
    cout << endl; 


    // Q1.4
    cout << "# Q1.4) Print the list recursively:" << endl;
    myList.printListRecursively(myList.head);
    cout << endl;


    // Q1.5
    cout << "# Q1.5) Print the list in reverse order:" << endl;
    myList.printListReverse();
    cout << endl;


    // Q1.6
    cout << "# Q1.6) Is list empty? (Returns 1 if empty or 0 if not empty) " << myList.isEmpty() << endl;
    cout << endl;


    // Q1.7
    cout << "# Q1.7) Return memory address of element 2 or 0 if it doesn't exists: " << myList.getNodePtr(2) << endl;
    cout << endl;


    // Q1.8
    cout << "# Q1.8) Remove element 2. " << endl;
    myList.deleteNode(2);
    cout << "Print the list:" << endl;
    myList.printList();
    cout << endl;


    // Q1.9
    cout << "# Q1.9) Remove element 2 recursively." << endl;
    myList.deleteNodeRecursively(2, myList.head);
    cout << "Print the list:" << endl;
    myList.printList();
    cout << endl;


    // Q1.10
    cout << "# Q1.10) Remove list." << endl;
    myList.deleteList();
    cout << "Print the list:" << endl;
    myList.printList();
    cout << endl;


    cout << "******* Test functions with elements in the list *******" << endl;
    cout << endl;


    // Q1.2
    cout << "# Q1.2) Insert elements 3, 12, 4 and 7." << endl;
    myList.insertNode(3);
    myList.insertNode(12);
    myList.insertNode(4);
    myList.insertNode(7);
    cout << endl;


    // Q1.3
    cout << "# Q1.3) Print the list:" << endl;
    myList.printList();
    cout << endl; 


    // Q1.4
    cout << "# Q1.4) Print the list recursively:" << endl;
    myList.printListRecursively(myList.head);
    cout << endl;


    // Q1.5
    cout << "# Q1.5) Print the list in reverse order:" << endl;
    myList.printListReverse();
    cout << endl;


    // Q1.6
    cout << "# Q1.6) Is list empty? (Returns 1 if empty or 0 if not empty)" << myList.isEmpty() << endl;
    cout << endl;

   
    // Q1.7
    cout << "# Q1.7) Return memory address of element or 0 if it doesn't exists: " << endl;
    cout << "* Element 1: " << myList.getNodePtr(1) << endl;
    cout << "* Element 3: " << myList.getNodePtr(3) << endl;
    cout << "* Element 12: " << myList.getNodePtr(12) << endl;
    cout << "* Element 7: " << myList.getNodePtr(7) << endl;
    cout << endl;


    // Q1.8
     cout << "# Q1.8) Remove elements: " << endl;
    cout << "Print the initial list:" << endl;
    myList.printList();
    cout << endl;

    cout << "* Remove 12." << endl;
    myList.deleteNode(12);
    cout << "Print the list:" << endl;
    myList.printList();
    cout << endl;

    cout << "* Remove 1." << endl;
    myList.deleteNode(1);
    cout << "Print the list:" << endl;
    myList.printList();
    cout << endl;

    cout << "* Remove 3." << endl;
    myList.deleteNode(3);
    cout << "Print the list:" << endl;
    myList.printList();
    cout << endl;

    cout << "* Remove 7." << endl;
    myList.deleteNode(7);
    cout << "Print the list:" << endl;
    myList.printList();
    cout << endl;

    cout << "* Remove 4." << endl;
    myList.deleteNode(4);
    cout << "Print the list:" << endl;
    myList.printList();
    cout << endl;
  

    cout << "Insert elements 9, 13, 100 and 1111." << endl;
    myList.insertNode(9);
    myList.insertNode(13);
    myList.insertNode(100);
    myList.insertNode(1111);
    cout << "Print the list:" << endl;
    myList.printList();
    cout << endl;

    
    // Q1.9
    cout << "# Q1.9) Remove elements recursively: " << endl;
    cout << "Print the initial list:" << endl;
    myList.printList();
    cout << endl;

    cout << "* Remove element 13." << endl;
    myList.deleteNodeRecursively(13, myList.head);
    cout << "Print the list:" << endl;
    myList.printList();
    cout << endl;

    cout << "* Remove element 1." << endl;
    myList.deleteNodeRecursively(1, myList.head);
    cout << "Print the list:" << endl;
    myList.printList();
    cout << endl;

    cout << "* Remove element 9." << endl;
    myList.deleteNodeRecursively(9, myList.head);
    cout << "Print the list:" << endl;
    myList.printList();
    cout << endl;

    cout << "* Remove element 1111." << endl;
    myList.deleteNodeRecursively(1111, myList.head);
    cout << "Print the list:" << endl;
    myList.printList();
    cout << endl;

    cout << "* Remove element 100." << endl;
    myList.deleteNodeRecursively(100, myList.head);
    cout << "Print the list:" << endl;
    myList.printList();
    cout << endl;


    cout << "Insert elements 5, 14 and 55." << endl;
    myList.insertNode(5);
    myList.insertNode(14);
    myList.insertNode(55);
    cout << "Print the list:" << endl;
    myList.printList();
    cout << endl;


    // Q1.10
    cout << "# Q1.10) Remove the list." << endl;
    myList.deleteList();
    cout << "Print the list:" << endl;
    myList.printList();
    cout << endl;


    return 0;
}
