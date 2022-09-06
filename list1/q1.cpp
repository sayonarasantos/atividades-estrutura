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

        Node* getPtr(int value) {
            for(Node* i = head; i != NULL; i = i->next) {
                if(i->value == value) {
                    return i;
                }
            }

            return NULL;
        }   

        void insertElement(int value) {
            Node* ptr = new Node(value);

            if(isEmpty() == 1) {
                head = ptr;
            } else {
                ptr->next = head;
                head = ptr;
            }

            ptr = NULL;
        }

        void removeElement(int value) {
            Node* elemPtr = getPtr(value);

            if(isEmpty() == 0) {
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

        void removeElementRecursively(int value, Node* ptr) {
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
                        removeElementRecursively(value, ptr->next);
                    }
                }
            }

            aux = NULL;
        }

        void removeList() {
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
        

        void getList() {     
            if(head != NULL) {
                for(Node* i = head; i != NULL; i = i->next) {
                    cout << i->value << endl;
                }
            } else {
                cout << "The list is empty." << endl;
            }
        }

        void getListRecursively(Node* ptr) {
            if(ptr != NULL) {
                cout << ptr->value << endl;
                getListRecursively(ptr->next);
            }
        }

        void getListReverse() {
            List auxList;
            Node* aux = head;

            if(head != NULL) {
                for(Node* i = head; i != NULL; i = i->next) {
                    auxList.insertElement(i->value);
                }
            }

            auxList.getList();
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
    cout << "# Q1.3) Printing the list..." << endl;
    myList.getList();
    cout << endl; 


    // Q1.4
    cout << "# Q1.4) Printing the list recursively..." << endl;
    myList.getListRecursively(myList.head);
    cout << endl;


    // Q1.5
    cout << "# Q1.5) Printing the list in reverse order..." << endl;
    myList.getListReverse();
    cout << endl;


    // Q1.6
    cout << "# Q1.6) Is list empty? (Returns 1 if empty or 0 if not empty.)" << myList.isEmpty() << endl;
    cout << endl;


    // Q1.7
    cout << "# Q1.7) Return memory address of element 2 or 0 if it doesn't exists: " << myList.getPtr(2) << endl;
    cout << endl;


    // Q1.8
    cout << "# Q1.8) Removing element 2..." << endl;
    myList.removeElement(2);
    cout << "Printing the list..." << endl;
    myList.getList();
    cout << endl;


    // Q1.9
    cout << "# Q1.9) Removing element 2 recursively..." << endl;
    myList.removeElementRecursively(2, myList.head);
    cout << "Printing the list..." << endl;
    myList.getList();
    cout << endl;


    // Q1.10
    cout << "# Q1.10) Remove list..." << endl;
    myList.removeList();
    cout << "Printing the list..." << endl;
    myList.getList();
    cout << endl;


    cout << "******* Test functions with elements in the list *******" << endl;
    cout << endl;


    // Q1.2
    cout << "# Q1.2) Inserting elements 3, 12, 4 and 7..." << endl;
    myList.insertElement(3);
    myList.insertElement(12);
    myList.insertElement(4);
    myList.insertElement(7);
    cout << endl;


    // Q1.3
    cout << "# Q1.3) Printing the list..." << endl;
    myList.getList();
    cout << endl; 


    // Q1.4
    cout << "# Q1.4) Printing the list recursively..." << endl;
    myList.getListRecursively(myList.head);
    cout << endl;


    // Q1.5
    cout << "# Q1.5) Printing the list in reverse order..." << endl;
    myList.getListReverse();
    cout << endl;


    // Q1.6
    cout << "# Q1.6) Is list empty? (Returns 1 if empty or 0 if not empty.)" << myList.isEmpty() << endl;
    cout << endl;

   
    // Q1.7
    cout << "# Q1.7) Return memory address of element 3 or 0 if it doesn't exists: " << myList.getPtr(3) << endl;
    cout << endl;

    cout << "# Q1.7) Return memory address of element 12 or 0 if it doesn't exists: " << myList.getPtr(12) << endl;
    cout << endl;

    cout << "# Q1.7) Return memory address of element 7 or 0 if it doesn't exists: " << myList.getPtr(7) << endl;
    cout << endl;


    // Q1.8
    cout << "# Q1.8) Removing element 12..." << endl;
    myList.removeElement(12);
    cout << "Printing the list..." << endl;
    myList.getList();
    cout << endl;

    cout << "# Q1.8) Removing element 7..." << endl;
    myList.removeElement(7);
    cout << "Printing the list..." << endl;
    myList.getList();
    cout << endl;

    cout << "# Q1.8) Removing element 3..." << endl;
    myList.removeElement(3);
    cout << "Printing the list..." << endl;
    myList.getList();
    cout << endl;

    cout << "# Q1.8) Removing element 4..." << endl;
    myList.removeElement(4);
    cout << "Printing the list..." << endl;
    myList.getList();
    cout << endl;
    

    cout << "Inserting elements 4, 13, 100 and 1111..." << endl;
    myList.insertElement(4);
    myList.insertElement(13);
    myList.insertElement(100);
    myList.insertElement(1111);
    cout << "Printing the list..." << endl;
    myList.getList();
    cout << endl;

    
    // Q1.9
    cout << "# Q1.9) Removing element 13 recursively..." << endl;
    myList.removeElementRecursively(13, myList.head);
    cout << "Printing the list..." << endl;
    myList.getList();
    cout << endl;

    cout << "# Q1.9) Removing element 1111 recursively..." << endl;
    myList.removeElementRecursively(1111, myList.head);
    cout << "Printing the list..." << endl;
    myList.getList();
    cout << endl;

    cout << "# Q1.9) Removing element 4 recursively..." << endl;
    myList.removeElementRecursively(4, myList.head);
    cout << "Printing the list..." << endl;
    myList.getList();
    cout << endl;

    cout << "# Q1.9) Removing element 100 recursively..." << endl;
    myList.removeElementRecursively(100, myList.head);
    cout << "Printing the list..." << endl;
    myList.getList();
    cout << endl;


    cout << "Inserting elements 5, 14 and 55..." << endl;
    myList.insertElement(5);
    myList.insertElement(14);
    myList.insertElement(55);
    cout << "Printing the list..." << endl;
    myList.getList();
    cout << endl;


    // Q1.10
    cout << "# Q1.10) Remove list..." << endl;
    myList.removeList();
    cout << "Printing the list..." << endl;
    myList.getList();
    cout << endl;

    return 0;
}
