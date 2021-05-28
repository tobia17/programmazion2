#ifndef BST_H
#define BST_H

#include <iostream>
#include "NodoBST.h"

using namespace std;

template <class T>
class BST {
    private:
        NodoBST<T> *root;

        void recursiveInsert(NodoBST<T> *nodo, NodoBST<T> *newNodo) {
            if(nodo->getValue() <= newNodo->getValue() && nodo->getSx() == NULL) {
                //caso base 1
                nodo->setSx(newNodo);
                newNodo->setParent(nodo);
                return;
            }

            if(nodo->getValue() > newNodo->getValue() && nodo->getDx() == NULL) {
                //caso base 2
                nodo->setDx(newNodo);
                newNodo->setParent(nodo);
                return;
            }

            if(nodo->getValue() <= newNodo->getValue()){
                recursiveInsert(nodo->getSx(), newNodo);
            }else{
                recursiveInsert(nodo->getDx(), newNodo);
            }
        }

        void recursivePrintASC(NodoBST<T> *nodo) {
            if(nodo == NULL) {
                return;
            }
            recursivePrintASC(nodo->getDx());
            cout << "\t" << *nodo << endl;
            recursivePrintASC(nodo->getSx());
        }

        void recursivePrintDESC(NodoBST<T> *nodo) {
            if(nodo == NULL) {
                return;
            }
            recursivePrintDESC(nodo->getSx());
            cout << "\t" << *nodo << endl;
            recursivePrintDESC(nodo->getDx());
        }

    public:

        BST() : root(NULL) {}

        void insert(T value) {
            NodoBST<T> *newNodo = new NodoBST<T>(value);

            if(root == NULL) {
                root = newNodo;
            }else {
                recursiveInsert(root, newNodo);
            }
        }

        void printASC() {
            cout << "Binary Search Tree Ascend (root: " << root << ")\n";
            recursivePrintASC(root);
        }

        void printDESC() {
            cout << "Binary Search Tree Descend (root: " << root << ")\n";
            recursivePrintDESC(root);
        }

};

#endif