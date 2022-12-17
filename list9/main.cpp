/*
 * AVL.h
 *
 *  Created on: 9 de dez de 2015
 *      Author: rparent
 */

#ifndef AVL_H_
#define AVL_H_

#include <iostream>
using namespace std;

class Node{
public:
	int value;
	int balanceFactor;
	Node *left, *right;

	Node(int nodeValue, int balanceValue = 0,Node *leftNode = NULL, Node *rightNode = NULL){
		value = nodeValue;
		balanceFactor = balanceValue;
		left = leftNode;
		right = rightNode;
	}
};

class AVL {
	Node *root;

	// Balance AVL tree
	void balanceTree(Node *father = root, Node *grandFather = NULL){
		calculateBalanceFactor();

		if(father != NULL){
			if(father->balanceFactor == -2){
				if(father->right->balanceFactor == -1){
					rotateLeft(father, grandFather);
					balanceTree();
				} else if(father->right->balanceFactor == 1){
					doubleRotateLeft(father, grandFather);
					balanceTree();
				}
			} else if(father->balanceFactor == 2){
				if(father->left->balanceFactor == 1){
					rotateRight(father, grandFather);
					balanceTree();
				} else if(father->left->balanceFactor == -1){
					doubleRotateRight(father, grandFather);
					balanceTree();
				}
			}
			balanceTree(father->left, father);
			balanceTree(father->right, father);
		}
	}

	// Calculate node balance factor
	void calculateBalanceFactor(Node *a = root){
		if(a != NULL){
			a->balanceFactor = nodeHeight(a->left) - nodeHeight(a->right);
			calculateBalanceFactor(a->left);
			calculateBalanceFactor(a->right);
		}
	}

	// Return node height
	int nodeHeight(Node *a){
		if(a == NULL){
			return -1;
		} else {
			int leftHeight = 1 + nodeHeight(a->left);
			int rightHeight = 1 + nodeHeight(a->right);

			return (leftHeight > rightHeight) ? leftHeight : rightHeight;
		}
	}

	/** Rotation Functions **/

	void rotateLeft(Node *father, Node *grandFather){
		Node *son = father->right;

		father->right = son->left;
		son->right = father;

		if(grandFather == NULL)
			root = son;
		else if(grandFather->left == father)
			grandFather->left = son;
		else if(grandFather->right == father)
			grandFather->right = son;
	}

	void rotateRight(Node *father, Node *grandFather){
		Node *son = father->left;

		father->left = son->right;
		son->right = father;

		if(grandFather == NULL)
			root = son;
		else if(grandFather->left == father)
			grandFather->left = son;
		else if(grandFather->right == father)
			grandFather->right = son;
	}

	void doubleRotateLeft(Node *father, Node *grandFather){
		Node *son = father->right;
		Node *leftSon = son->left;

		son->left = leftSon->right;
		leftSon->right = son;

		father->right = leftSon->left;
		leftSon->left = father;

		if(grandFather == NULL)
			root = leftSon;
		else if(grandFather->left == father)
			grandFather->left = leftSon;
		else if(grandFather->right == father)
			grandFather->right = leftSon;
	}

	void doubleRotateRight(Node *father, Node *grandFather){
		Node *son = father->left;
		Node *rightSon = son->right;

		son->right = rightSon->left;
		rightSon->left = son;

		father->left = rightSon->right;
		rightSon->right = father;

		if(grandFather == NULL)
			root = rightSon;
		else if(grandFather->left == father)
			grandFather->left = rightSon;
		else if(grandFather->right == father)
			grandFather->right = rightSon;
	}

	/** Search Functions **/

	Node searchNode(int value){
		Node *aux = root;

		while(true){
			if(aux->value == value)
				break;
			else if(value < aux->value)
				aux = aux->left;
			else if(value > aux->value)
				aux = aux->right;
		}
		return aux;
	}

	Node searchFather(Node *son){
		Node *aux = root;
		if(son == aux)
			return NULL;
		else {
			while(true){
				if(son->value < aux->value){
					if(son->value == aux->left->value)
						break;
					aux = aux->left;
				} else if(son->value > aux->value){
					if(son->value == aux->right->value)
						break;
					aux = aux->right;
				}
			}
		}
		return aux;
	}
public:
	AVL(){
		root = NULL;
	}

	bool isEmpty(){
		if(root == NULL)
			return true;
		else
			return false;
	}

	void insert(int a){
		Node *newNode = new Node(a);

		if(isEmpty()){
			root = newNode;
		} else {
			Node *aux = root;

			while(true){
				if(a < aux->value){
					if(aux->left == NULL){
						aux->left = newNode;
						break; // break out of loop
					}

					aux = aux->left;
				} else if(a > aux->value) {
					if(aux->right == NULL){
						aux->right = newNode;
						break; // break out of loop
					}

					aux = aux->right;
				}
			}

			balanceTree();
		}
	}

};

#endif /* AVL_H_ */