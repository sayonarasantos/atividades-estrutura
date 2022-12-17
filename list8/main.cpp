#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

class BST {

    private:

        Node* _insertNodeRecursively(Node *node, int key)
        {
            if(node == NULL) {
                node = new Node;
                node->data = key;
                node->right = nullptr;
                node->left = nullptr;

                return node;
            } 
            
            if(key > node->data)
                node->right = _insertNodeRecursively(node->right, key);
            else 
                node->left = _insertNodeRecursively(node->left, key);

            return node;
        }

        void _printTree(Node *node, string indent, bool last) {
            if (node != NULL) {
                cout << indent;
                if (last) {
                    cout << "R----";
                    indent += "   ";
                } else {
                    cout << "L----";
                    indent += "|  ";
                }

                cout << node->data << endl;
                _printTree(node->left, indent, false);
                _printTree(node->right, indent, true);
            }
        }

        void _deleteTree(Node *node)
        {
            if(node == nullptr) 
                return;

            _deleteTree(node->left);
            _deleteTree(node->right);

            node->left = nullptr;
            node->right = nullptr;
            delete node;
        }

    public:

        Node *root;

        BST() 
        {
            this->root = NULL;
        }

        void insertNode(int key)
        {
            Node *newNode = new Node;
            newNode->data = key;
            newNode->left = nullptr;
            newNode->right = nullptr;

            if(!this->root) {
                this->root = newNode;
                return;
            }

            Node *parent = NULL;
            Node *tmp = this->root;

            // obtaining parent
            // of the correct leaf
            while(tmp) {
                if(key > tmp->data) {
                    parent = tmp;
                    tmp = tmp->right;
                } else {
                    parent = tmp;
                    tmp = tmp->left;
                }
            }

            if(key > parent->data)
                parent->right = newNode;
            else
                parent->left = newNode;
        }

        void insertNodeRecursively(int key)
        {
            this->root = _insertNodeRecursively(this->root, key);
        }

        void deleteNode(int key)
        {
            Node *parent = NULL;
            Node *curr = this->root;

            // checking if key exists
            while(curr != NULL && curr->data != key) {
                parent = curr;
                
                if(key > curr->data)
                    curr = curr->right;
                else
                    curr = curr->left;
            }

            if(curr == NULL) {
                cout << key << " not found in the BST." << endl;
                return;
            }

            // CASE 1: node to be 
            // deleted has atmost one child
            if(curr->left == NULL || curr->right == NULL) {
                Node *newCurr;

                if(curr->left == NULL)
                    newCurr = curr->right;
                else
                    newCurr = curr->left;

                if(parent == NULL)
                    return;

                if(curr == parent->left)
                    parent->left = newCurr;
                else
                    parent->right = newCurr;

                // free memory of the node to be deleted
                free(curr);
            } 
            // CASE 2: node to be 
            // deleted has two child
            else {
                Node *parent = NULL;
                Node *tmp = curr->right;

                // finding inorder successor
                while(tmp->left != NULL) {
                    parent = tmp;
                    tmp = tmp->left;
                }

                if(parent != NULL)
                    parent->left = tmp->right;
                else
                    curr->right = tmp->right;

                curr->data = tmp->data;
                free(tmp);
            }
        }

        void searchNode(int key) {
            if(this->root == NULL) {
                cout << key << " not found in the BST." << endl;
                return;
            }

            Node *currNode = this->root;

            while(true) {
                if(currNode == NULL || key == currNode->data) {
                    cout << key << " found in the BST." << endl;
                    return;
                }

                if(key > currNode->data)
                    currNode = currNode->right;
                else
                    currNode = currNode->left;
            }
        }

        void printTree() 
        {
            if (this->root)
                _printTree(this->root, "", true);
            else
                cout << "The tree is empty." << endl;
        }

        void deleteTree() {
            _deleteTree(this->root);
            this->root = nullptr;
        }
};


int main(int argc, char const *argv[])
{

    BST tree;

    tree.insertNode(10);
    tree.insertNode(7);
    tree.insertNode(5);
    tree.insertNode(8);
    tree.insertNode(15);
    tree.insertNode(11);
    tree.insertNode(18);

    tree.printTree();

    cout << endl;

    tree.deleteNode(11);
    tree.deleteNode(15);
    tree.deleteNode(10);

    tree.printTree();

    cout << endl;

    tree.deleteTree();

    tree.insertNodeRecursively(50);
    tree.insertNodeRecursively(30);
    tree.insertNodeRecursively(20);
    tree.insertNodeRecursively(40);
    tree.insertNodeRecursively(70);
    tree.insertNodeRecursively(60);
    tree.insertNodeRecursively(80);

    cout << endl;

    tree.printTree();

    return 0;
}