#ifndef SIMPLELIST_H_
#define SIMPLELIST_H_

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

        ~List() {
            deleteList();
        }

        void deleteList() {
            Node* aux = NULL;

            while(!isEmpty()) {
                aux = head;
                head = aux->next;
                delete aux;
                aux = NULL;
            }
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

        void addNode(int value) {
            Node* ptr = new Node(value);

            if(!isEmpty()) {
                ptr->next = head;
            }

            head = ptr;
        }

        bool deleteNode(int value) {
            Node* elemPtr = getNodePtr(value);
            bool response = false;

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

                response = true;
            }

            delete elemPtr;
            elemPtr = NULL;
            return response;
        }
};

#endif