#include <iostream>
using namespace std;

int BLACK = 0;
int RED = 1;

struct Node
{
    int data;
    int color;
    Node *parent;
    Node *left;
    Node *right;
};

class RBTree {
    
    private:
        void printHelper(Node *root, string indent, bool last) {
            if (root != TNULL) {
                cout << indent;
                if (last) {
                    cout << "R----";
                    indent += "   ";
                } else {
                    cout << "L----";
                    indent += "|  ";
                }

                string sColor = root->color ? "RED" : "BLACK";
                cout << root->data << "(" << sColor << ")" << endl;
                printHelper(root->left, indent, false);
                printHelper(root->right, indent, true);
            }
        }

        void deleteTreeHelper(Node *node)
        {
            if(node == TNULL) 
                return;

            deleteTreeHelper(node->left);
            deleteTreeHelper(node->right);

            node->left = nullptr;
            node->right = nullptr;
            delete node;
        }

    public:
        Node *root;
        Node *TNULL;   // template to avoid getting an error when trying  
                       // to access left or right children of a null node

        RBTree() 
        {
            TNULL = new Node;
            TNULL->color = BLACK;        // root node is always BLACK
            TNULL->data = -1;
            TNULL->parent = nullptr;
            TNULL->left = nullptr;
            TNULL->right = nullptr;

            root = TNULL;
        }

        void insertNode(int key)
        {
            Node *newNode = new Node;
            newNode->color = RED;  // every new node is always RED
            newNode->data = key;
            newNode->parent = nullptr;
            newNode->left = TNULL;
            newNode->right = TNULL;

            Node *leaf = nullptr;
            Node *x = this->root;

            // traversing tree to
            // find the correct leaf
            while(x != TNULL) {
                leaf = x;

                if(newNode->data > x->data)
                    x = x->right;
                else
                    x = x->left;
            }

            newNode->parent = leaf;

            if(leaf == nullptr)
                root = newNode;
            else if (newNode->data > leaf->data)
                leaf->right = newNode;
            else
                leaf->left = newNode;

            // tree is empty
            if(newNode->parent == nullptr) {
                newNode->color = BLACK;
                return;
            }

            if(newNode->parent->parent == nullptr)
                return;

            fixInsertion(newNode);
        }

        void fixInsertion(Node *newNode)
        {
            Node *uncle;

            while (newNode->parent->color == RED) {
                // if the parent of newNode is equal  
                // to the left child of its grandparent
                if (newNode->parent == newNode->parent->parent->left) {
                    
                    uncle = newNode->parent->parent->right;

                    // CASE 1: the color of the 
                    // grandparent right child is RED
                    if (uncle->color == RED) {
                        uncle->color = BLACK;
                        newNode->parent->color = BLACK;
                        newNode->parent->parent->color = RED;
                        newNode = newNode->parent->parent;
                    } else {
                       
                        // CASE 2: newNode is the 
                        // right children of its parent
                        if (newNode == newNode->parent->right) {
                            newNode = newNode->parent;
                            rotateLeft(newNode);
                        }

                        newNode->parent->color = BLACK;
                        newNode->parent->parent->color = RED;
                        rotateRight(newNode->parent->parent);
                    }
                } else {
                    
                    uncle = newNode->parent->parent->left;
                    
                    // CASE 3: the color of the 
                    // grandparent left child is RED
                    if (uncle->color == RED) {
                        uncle->color = BLACK;
                        newNode->parent->color = BLACK;
                        newNode->parent->parent->color = RED;
                        newNode = newNode->parent->parent;
                    } else {

                        // CASE 4: newNode is the 
                        // left children of its parent
                        if (newNode == newNode->parent->left) {
                            newNode = newNode->parent;
                            rotateRight(newNode);
                        }

                        newNode->parent->color = BLACK;
                        newNode->parent->parent->color = RED;
                        rotateLeft(newNode->parent->parent);
                    }
                }

                if(newNode == root)
                    break;
            }

            root->color = 0;
        }

        void rotateLeft(Node *x) 
        {
            Node *y = x->right;
            x->right = y->left;
            
            if (y->left != TNULL) {
                y->left->parent = x;
            }
            
            y->parent = x->parent;
            
            if (x->parent == nullptr) {
                this->root = y;
            } else if (x == x->parent->left) {
                x->parent->left = y;
            } else {
                x->parent->right = y;
            }

            y->left = x;
            x->parent = y;
        }

        void rotateRight(Node *x) 
        {
            Node *y = x->left;
            x->left = y->right;
            
            if (y->right != TNULL) {
                y->right->parent = x;
            }
            
            y->parent = x->parent;
            
            if (x->parent == nullptr) {
                this->root = y;
            } else if (x == x->parent->right) {
                x->parent->right = y;
            } else {
                x->parent->left = y;
            }
            
            y->right = x;
            x->parent = y;
        }

        Node* searchNode(int key) {
            Node *currNode = this->root;

            while(true) {
                if(currNode == TNULL || key == currNode->data)
                    return currNode;

                if(key > currNode->data)
                    currNode = currNode->right;
                else
                    currNode = currNode->left;
            }
        }

        void printTree() {
            if (this->root)
                printHelper(this->root, "", true);
            else
                cout << "The tree is empty." << endl;
        }

        void deleteTree() {
            deleteTreeHelper(this->root);
            this->root = TNULL;
        }
};

int main(int argc, char const *argv[])
{

    RBTree tree;

    tree.insertNode(55);
    tree.insertNode(40);
    tree.insertNode(65);
    tree.insertNode(60);
    tree.insertNode(75);
    tree.insertNode(57);

    tree.printTree();

    cout << tree.searchNode(75)->data << endl;

    tree.deleteTree();

    tree.printTree();

    return 0;
}